#include "PolyHedra/InstanceManager.hpp"
#include "PolyHedra/ObjectData.hpp"

#include "PolyHedra/PolyHedra.hpp"
#include "Miscellaneous/Container/Pointer.hpp"
#include "PolyHedra/Graphics/Full/Main/Data.hpp"
#include "Miscellaneous/Container/Array.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"



PolyHedraInstanceManager::~PolyHedraInstanceManager()
{ }
PolyHedraInstanceManager::PolyHedraInstanceManager()
	: PolyHedra(nullptr)
	, PolyHedraChanged(false)
	, BufferFull()
	, Instances()
{ }
PolyHedraInstanceManager::PolyHedraInstanceManager(const PolyHedraInstanceManager & other)
	: PolyHedra(other.PolyHedra)
	, PolyHedraChanged(other.PolyHedraChanged)
	, BufferFull(other.BufferFull)
	, Instances()
{ }
PolyHedraInstanceManager & PolyHedraInstanceManager::operator=(const PolyHedraInstanceManager & other)
{
	PolyHedra = other.PolyHedra;
	PolyHedraChanged = other.PolyHedraChanged;
	BufferFull = other.BufferFull;
	Instances.Clear();
	return *this;
}

PolyHedraInstanceManager::PolyHedraInstanceManager(::PolyHedra * polyhedra)
	: PolyHedra(polyhedra)
	, PolyHedraChanged(true)
	, BufferFull()
	, Instances()
{ }
void PolyHedraInstanceManager::Change(::PolyHedra * polyhedra)
{
	PolyHedra = polyhedra;
	PolyHedraChanged = true;
}



void PolyHedraInstanceManager::GraphicsCreate()
{
	BufferFull.Create();
}
void PolyHedraInstanceManager::GraphicsDelete()
{
	BufferFull.Delete();
}

void PolyHedraInstanceManager::InitExternal()
{ }
void PolyHedraInstanceManager::InitInternal()
{
	BufferFull.Main.Init();
	BufferFull.Inst.Init();
}



void PolyHedraInstanceManager::UpdateBufferMain()
{
	if (PolyHedra == nullptr) { return; }

	Container::Pointer<PolyHedraFull::Main::Data> data = PolyHedra -> ToMainData();
	BufferFull.Main.Change(data);
	data.Clear();

	if (PolyHedra -> Skin != NULL)
	{
		//_Texture = _PolyHedra -> Skin -> ToTexture();
		Skin2DA * skin = (Skin2DA*)(PolyHedra -> Skin);
		//skin -> ToTexture(Buffer.Texture);
		skin -> ToTexture(Texture);
	}
	else
	{
		//_Texture = NULL;
		//Buffer.Texture.Delete();
		Texture.Delete();
	}
}
void PolyHedraInstanceManager::UpdateBufferInst()
{
	BufferFull.Inst.Change(Instances);
}
void PolyHedraInstanceManager::DrawFull()
{
	if (PolyHedraChanged)
	{
		UpdateBufferMain();
		PolyHedraChanged = false;
	}
	UpdateBufferInst();
	Texture.Bind();
	BufferFull.Draw();
}



void PolyHedraInstanceManager::Clear()
{
	Instances.Clear();
}
void PolyHedraInstanceManager::Place(const PolyHedraObjectData & obj)
{
	if (obj.PolyHedra == PolyHedra)
	{
		Instances.Insert(Instance::Basic3D::Data(obj.Trans));
	}
}
void PolyHedraInstanceManager::Place(const Container::Member<PolyHedraObjectData> & objs)
{
	for (unsigned int i = 0; i < objs.Count(); i++)
	{
		Place(objs[i]);
	}
}
