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
	: ObjectDatas()
	, GraphicsExist(false)
	, ShaderFullDefault()
	, ShaderWireDefault()
	, ShaderFullOther(nullptr)
	, ShaderWireOther(nullptr)
	, InstanceManagers()
{ }



void PolyHedraManager::GraphicsCreate()
{
	if (GraphicsExist) { return; }

	ShaderFullDefault.Create();
	ShaderWireDefault.Create();
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
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

void PolyHedraManager::InitExternal(DirectoryInfo & media_dir)
{
	{
		Container::Array<Shader::Code> code({
			Shader::Code(media_dir.File("Shaders/Basic3D/Full.vert")),
			Shader::Code(media_dir.File("Shaders/Basic3D/Full.frag")),
		});
		ShaderFullDefault.Change(code);
	}
	{
		Container::Array<Shader::Code> code({
			Shader::Code(media_dir.File("Shaders/Basic3D/Wire.vert")),
			Shader::Code(media_dir.File("Shaders/Basic3D/Wire.frag")),
		});
		ShaderWireDefault.Change(code);
	}
	// Buffer Bindings depend on Shaders, should be done here ?
	// Shaders depend on outside, and should be set outside ?
	// every InstanceManager has its own Buffer
	// would need a Template for how to set things ?
	// maybe just a Buffer that is never actually created
	// this might have been easier to just hardcode with OpenGL
	// instead of doing all of this "Wrapper" stuff that I have made
}
void PolyHedraManager::InitInternal() { }



unsigned int PolyHedraManager::FindPolyHedra(::PolyHedra * polyhedra)
{
	for (unsigned int i = 0; i < InstanceManagers.Count(); i++)
	{
		if (InstanceManagers[i].PolyHedra == polyhedra)
		{
			return i;
		}
	}
	return 0xFFFFFFFF;
}
unsigned int PolyHedraManager::PlacePolyHedra(::PolyHedra * polyhedra)
{
	unsigned int idx = InstanceManagers.Count();
	InstanceManagers.Insert(PolyHedraInstanceManager(polyhedra));
	if (GraphicsExist)
	{
		InstanceManagers[idx].GraphicsCreate();
	}
	return idx;
}

PolyHedraObjectData * PolyHedraManager::PlaceObject(unsigned int polyhedra, Trans3D trans)
{
	PolyHedraObjectData * obj = new PolyHedraObjectData(InstanceManagers[polyhedra].PolyHedra);
	obj -> Trans = trans;
	obj -> DrawFull = InstanceManagers[polyhedra].DefaultFullVisibility;
	obj -> DrawWire = InstanceManagers[polyhedra].DefaultWireVisibility;
	ObjectDatas.Insert(obj);
	return obj;
}
PolyHedraObjectData * PolyHedraManager::PlaceObject(::PolyHedra * polyhedra, Trans3D trans)
{
	unsigned int idx = FindPolyHedra(polyhedra);
	if (idx == 0xFFFFFFFF)
	{
		idx = PlacePolyHedra(polyhedra);
	}
	return PlaceObject(idx, trans);
}
PolyHedraObjectData * PolyHedraManager::CopyObject(const PolyHedraObjectData * obj)
{
	if (obj == nullptr) { return nullptr; }
	return PlaceObject(obj -> PolyHedra, obj -> Trans);
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
void PolyHedraManager::UpdateInstances()
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
				ObjectDatas.Remove(i);
				delete &obj;
				i--;
			}
		}
	}
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
