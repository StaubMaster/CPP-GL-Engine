#include "PolyHedra/Manager.hpp"
#include "PolyHedra/ObjectData.hpp"

#include "DirectoryInfo.hpp"
#include "Graphics/Shader/Code.hpp"
#include "Miscellaneous/Container/Array.hpp"





PolyHedraManager * PolyHedraManager::CurrentPointer = nullptr;
PolyHedraManager & PolyHedraManager::Current() { return *CurrentPointer; }
bool PolyHedraManager::CheckCurrent() { return (PolyHedraManager::CurrentPointer != nullptr); }
void PolyHedraManager::ClearCurrent() { PolyHedraManager::CurrentPointer = nullptr; }
bool PolyHedraManager::IsCurrent() const { return (PolyHedraManager::CurrentPointer == this); }
void PolyHedraManager::MakeCurrent() { PolyHedraManager::CurrentPointer = this; }





PolyHedraManager::~PolyHedraManager()
{ }
PolyHedraManager::PolyHedraManager()
	: InstanceManagers()
	, GraphicsExist(false)
	, ShaderFullDefault()
	, ShaderWireDefault()
	, ShaderFullOther(nullptr)
	, ShaderWireOther(nullptr)
	, ShaderLayoutFullDefault()
	, BufferLayoutFullMain()
	, BufferLayoutFullInst()
	, ShaderLayoutWireDefault()
	, BufferLayoutWireMain()
	, BufferLayoutWireInst()
{
	ShaderFullDefault.UniformLayout = &ShaderLayoutFullDefault;
	ShaderLayoutFullDefault.Shader = &ShaderFullDefault;

	ShaderWireDefault.UniformLayout = &ShaderLayoutWireDefault;
	ShaderLayoutWireDefault.Shader = &ShaderWireDefault;
}



void PolyHedraManager::MakeInstances()
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			InstanceManagers[i] -> MakeInstances();
		}
	}
}

::PolyHedraPalletManager * PolyHedraManager::FindPallet(::PolyHedra * pallet)
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			if (InstanceManagers[i] -> Pallet == pallet)
			{
				return InstanceManagers[i];
			}
		}
	}
	return nullptr;
}
::PolyHedraPalletManager * PolyHedraManager::MakePallet(::PolyHedra * pallet)
{
	PolyHedraPalletManager * manager = FindPallet(pallet);
	if (manager != nullptr)
	{
		return manager;
	}
	manager = new PolyHedraPalletManager(pallet);
	if (GraphicsExist)
	{
		manager -> ChangeMedia(*this);
		manager -> GraphicsCreate();
	}
	InstanceManagers.Insert(manager);
	return manager;
}



PolyHedraObjectData * PolyHedraManager::MakeObject(::PolyHedraPalletManager * pallet)
{
	if (pallet == nullptr) { return nullptr; }
	return pallet -> MakeObject();
}
PolyHedraObjectData * PolyHedraManager::MakeObject(::PolyHedra * pallet)
{
	PolyHedraPalletManager * manager = MakePallet(pallet);
	return MakeObject(manager);
}



PolyHedraObjectData * PolyHedraManager::TryMakeObject(PolyHedraManager * manager, ::PolyHedraPalletManager * pallet)
{
	if (manager == nullptr) { manager = PolyHedraManager::CurrentPointer; }
	if (manager == nullptr) { return nullptr; }
	return manager -> MakeObject(pallet);
}
PolyHedraObjectData * PolyHedraManager::TryMakeObject(PolyHedraManager * manager, ::PolyHedra * pallet)
{
	if (manager == nullptr) { manager = PolyHedraManager::CurrentPointer; }
	if (manager == nullptr) { return nullptr; }
	return manager -> MakeObject(pallet);
}



void PolyHedraManager::ChangeMedia(const DirectoryInfo & dir)
{
	{
		ShaderFullDefault.Change({
			dir.File("Shaders/Basic3D/Full.vert"),
			dir.File("Shaders/Basic3D/Full.frag"),
		});
	}
	{
		BufferLayoutFullMain.Position.Change(0);
		BufferLayoutFullMain.Normal.Change(1);
		BufferLayoutFullMain.Texture.Change(2);
		BufferLayoutFullInst.Trans.Change(3);
		BufferLayoutFullInst.Normal.Change(7);
	}
	{
		ShaderWireDefault.Change({
			dir.File("Shaders/Basic3D/Wire.vert"),
			dir.File("Shaders/Basic3D/Wire.frag"),
		});
	}
	{
		BufferLayoutWireMain.Pos.Change(0);
		BufferLayoutWireMain.Col.Change(1);
		BufferLayoutWireInst.Trans.Change(3);
		BufferLayoutWireInst.Normal.Change(-1);
	}
}

void PolyHedraManager::GraphicsCreate()
{
	if (GraphicsExist) { return; }

	ShaderFullDefault.Create();
	ShaderWireDefault.Create();
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			InstanceManagers[i] -> ChangeMedia(*this);
			InstanceManagers[i] -> GraphicsCreate();
		}
	}

	GraphicsExist = true;
}
void PolyHedraManager::GraphicsDelete()
{
	if (!GraphicsExist) { return; }

	ShaderFullDefault.Delete();
	ShaderWireDefault.Delete();
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			InstanceManagers[i] -> GraphicsDelete();
		}
	}

	GraphicsExist = false;
}

void PolyHedraManager::DrawFull()
{
	if (ShaderFullOther == nullptr)
	{
		ShaderFullDefault.Bind();
	}
	else
	{
		ShaderFullOther -> Bind();
	}
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			InstanceManagers[i] -> DrawFull();
		}
	}
}
void PolyHedraManager::DrawWire()
{
	if (ShaderWireOther == nullptr)
	{
		ShaderWireDefault.Bind();
	}
	else
	{
		ShaderWireOther -> Bind();
	}
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i] != nullptr)
		{
			InstanceManagers[i] -> DrawWire();
		}
	}
}
