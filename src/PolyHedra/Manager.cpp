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
	, ObjectDatas()
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



void PolyHedraManager::ClearInstances()
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		InstanceManagers[i].ClearInstances();
	}
}
void PolyHedraManager::PlaceInstance(const PolyHedraObjectData & obj)
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		InstanceManagers[i].PlaceInstance(obj);
	}
}
void PolyHedraManager::MakeInstances()
{
	ClearInstances();
	for (unsigned int i = 0; i < ObjectDatas.Count(); i++)
	{
		if (ObjectDatas[i] != nullptr)
		{
			PolyHedraObjectData & obj = *ObjectDatas[i];
			PlaceInstance(obj);
			if (obj.Remove)
			{
				ObjectDatas.RemoveAt(i);
				delete &obj;
				i--;
			}
		}
	}
}

::PolyHedraPalletManager * PolyHedraManager::FindPallet(::PolyHedra * pallet)
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i].Pallet == pallet)
		{
			return &InstanceManagers[i];
		}
	}
	return nullptr;
}
::PolyHedraPalletManager * PolyHedraManager::PlacePallet(::PolyHedra * pallet)
{
	unsigned int idx = InstanceManagers.Count();
	InstanceManagers.Insert(PolyHedraPalletManager(pallet));
	if (GraphicsExist)
	{
		InstanceManagers[idx].ChangeMedia(*this);
		InstanceManagers[idx].GraphicsCreate();
	}
	return &InstanceManagers[idx];
}



PolyHedraObjectData * PolyHedraManager::PlaceObject(::PolyHedraPalletManager * pallet)
{
	if (pallet == nullptr) { return nullptr; }
	PolyHedraObjectData * obj = new PolyHedraObjectData(pallet);
	//obj -> Trans = trans;
	obj -> DrawFull = pallet -> DefaultVisibilityWire;
	obj -> DrawWire = pallet -> DefaultVisibilityWire;
	ObjectDatas.Insert(obj);
	return obj;
}
PolyHedraObjectData * PolyHedraManager::PlaceObject(::PolyHedra * pallet)
{
	::PolyHedraPalletManager * manager = FindPallet(pallet);
	if (manager == nullptr)
	{
		manager = PlacePallet(pallet);
	}
	return PlaceObject(manager);
}
PolyHedraObjectData * PolyHedraManager::CopyObject(const PolyHedraObjectData * obj)
{
	if (obj == nullptr) { return nullptr; }
	return PlaceObject(obj -> PalletManager);
}



PolyHedraObjectData * PolyHedraManager::sPlaceObject(::PolyHedraPalletManager * pallet)
{
	if (CurrentPointer != nullptr)
	{
		return CurrentPointer -> PlaceObject(pallet);
	}
	return nullptr;
}
PolyHedraObjectData * PolyHedraManager::sPlaceObject(::PolyHedra * pallet)
{
	if (CurrentPointer != nullptr)
	{
		return CurrentPointer -> PlaceObject(pallet);
	}
	return nullptr;
}
PolyHedraObjectData * PolyHedraManager::sCopyObject(const PolyHedraObjectData * obj)
{
	if (CurrentPointer != nullptr)
	{
		return CurrentPointer -> CopyObject(obj);
	}
	return nullptr;
}



void PolyHedraManager::ChangeMedia(const DirectoryInfo & dir)
{
	{
		Container::Array<Shader::Code> code({
			Shader::Code(dir.File("Shaders/Basic3D/Full.vert")),
			Shader::Code(dir.File("Shaders/Basic3D/Full.frag")),
		});
		ShaderFullDefault.Change(code);
	}
	{
		BufferLayoutFullMain.Position.Change(0);
		BufferLayoutFullMain.Normal.Change(1);
		BufferLayoutFullMain.Texture.Change(2);
		BufferLayoutFullInst.Trans.Change(3);
		BufferLayoutFullInst.Normal.Change(7);
	}
	{
		Container::Array<Shader::Code> code({
			Shader::Code(dir.File("Shaders/Basic3D/Wire.vert")),
			Shader::Code(dir.File("Shaders/Basic3D/Wire.frag")),
		});
		ShaderWireDefault.Change(code);
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
		InstanceManagers[i].ChangeMedia(*this);
		InstanceManagers[i].GraphicsCreate();
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
		InstanceManagers[i].GraphicsDelete();
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
		InstanceManagers[i].DrawFull();
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
		InstanceManagers[i].DrawWire();
	}
}
