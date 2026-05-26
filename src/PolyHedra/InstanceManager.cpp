#include "PolyHedra/InstanceManager.hpp"
#include "PolyHedra/ObjectData.hpp"

#include "Miscellaneous/Container/Array.hpp"
#include "Miscellaneous/Container/Binary.hpp"

#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Graphics/Full/Main/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"



PolyHedraInstanceManager::~PolyHedraInstanceManager()
{ }
PolyHedraInstanceManager::PolyHedraInstanceManager()
	: PolyHedra(nullptr)
	, DefaultFullVisibility(true)
	, DefaultWireVisibility(false)
	, UpdateFullMain(false)
	, UpdateWireMain(false)
	, GraphicsExist(false)
	, BufferFull()
	, BufferWire()
	, Texture()
	, InstancesFull()
	, InstancesWire()
{ }
PolyHedraInstanceManager::PolyHedraInstanceManager(const PolyHedraInstanceManager & other)
	: PolyHedra(other.PolyHedra)
	, DefaultFullVisibility(other.DefaultFullVisibility)
	, DefaultWireVisibility(other.DefaultWireVisibility)
	, UpdateFullMain(other.UpdateFullMain)
	, UpdateWireMain(other.UpdateWireMain)
	, GraphicsExist(other.GraphicsExist)
	, BufferFull(other.BufferFull)
	, BufferWire(other.BufferWire)
	, Texture(other.Texture)
	, InstancesFull()
	, InstancesWire()
{ }
PolyHedraInstanceManager & PolyHedraInstanceManager::operator=(const PolyHedraInstanceManager & other)
{
	PolyHedra = other.PolyHedra;
	DefaultFullVisibility = other.DefaultFullVisibility;
	DefaultWireVisibility = other.DefaultWireVisibility;
	UpdateFullMain = other.UpdateFullMain;
	UpdateWireMain = other.UpdateWireMain;
	GraphicsExist = other.GraphicsExist;
	BufferFull = other.BufferFull;
	BufferWire = other.BufferWire;
	Texture = other.Texture;
	InstancesFull.Clear();
	InstancesWire.Clear();
	return *this;
}

PolyHedraInstanceManager::PolyHedraInstanceManager(::PolyHedra * polyhedra)
	: PolyHedra(polyhedra)
	, UpdateFullMain(true)
	, UpdateWireMain(true)
	, GraphicsExist(false)
	, BufferFull()
	, BufferWire()
	, InstancesFull()
	, InstancesWire()
{ }
void PolyHedraInstanceManager::Change(::PolyHedra * polyhedra)
{
	PolyHedra = polyhedra;
	UpdateFullMain = true;
	UpdateWireMain = true;
}



void PolyHedraInstanceManager::GraphicsCreate()
{
	if (!GraphicsExist)
	{
		BufferFull.Create();
		BufferWire.Create();
		GraphicsExist = true;

		LayoutMainFull.Position.Change(0);
		LayoutMainFull.Normal.Change(1);
		LayoutMainFull.Texture.Change(2);
		LayoutInstFull.Trans.Change(3);
		LayoutInstFull.Normal.Change(7);

		LayoutMainWire.Pos.Change(0);
		LayoutMainWire.Col.Change(1);
		LayoutInstWire.Trans.Change(3);
		LayoutInstWire.Normal.Change(-1);

		BufferFull.MainBuffer.AttributeLayout = &LayoutMainFull;
		BufferFull.InstBuffer.AttributeLayout = &LayoutInstFull;
		BufferWire.MainBuffer.AttributeLayout = &LayoutMainWire;
		BufferWire.InstBuffer.AttributeLayout = &LayoutInstWire;

		BufferFull.MainBuffer.AttributesBound = false;
		BufferFull.InstBuffer.AttributesBound = false;
		BufferWire.MainBuffer.AttributesBound = false;
		BufferWire.InstBuffer.AttributesBound = false;
	}
}
void PolyHedraInstanceManager::GraphicsDelete()
{
	if (GraphicsExist)
	{
		BufferFull.Delete();
		BufferWire.Delete();
		GraphicsExist = false;
	}
}



void PolyHedraInstanceManager::UpdateFullBufferInit()
{
	if (!GraphicsExist) { return; }

	BufferFull.MainBuffer.Update();
	BufferFull.InstBuffer.Update();
}
void PolyHedraInstanceManager::UpdateFullBufferMain()
{
	if (!(UpdateFullMain && PolyHedra != nullptr && GraphicsExist)) { return; }

	{
		Container::Array<PolyHedraFull::Main::Data> data = PolyHedra -> ToMainData();
		BufferFull.MainBuffer.DataFull(data.ToVoid());
	}

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

	UpdateFullMain = false;
}
void PolyHedraInstanceManager::UpdateFullBufferInst()
{
	BufferFull.InstBuffer.DataFull(InstancesFull.ToVoid());
}
void PolyHedraInstanceManager::DrawFull()
{
	UpdateFullBufferInit();
	UpdateFullBufferMain();
	UpdateFullBufferInst();
	Texture.Bind();
	BufferFull.Draw();
}

void PolyHedraInstanceManager::UpdateWireBufferInit()
{
	if (!GraphicsExist) { return; }

	BufferWire.MainBuffer.Update();
	BufferWire.InstBuffer.Update();
}
void PolyHedraInstanceManager::UpdateWireBufferMain()
{
	if (!(UpdateWireMain && PolyHedra != nullptr && GraphicsExist)) { return; }

	{
		Container::Binary<PolyHedraWire::Main::Data> data;
		for (unsigned int i = 0; i < PolyHedra -> Corners.Count(); i++)
		{
			data.Insert(PolyHedraWire::Main::Data(PolyHedra -> Corners[i].Position, ColorF4(1, 1, 1)));
		}
		BufferWire.MainBuffer.DataFull(data.ToVoid());
	}
	{
		/*Container::Binary<PolyHedra::Edge> data;
		for (unsigned int i = 0; i < PolyHedra -> Faces.Count(); i++)
		{
			const PolyHedra::Face & face = PolyHedra -> Faces[i];
			if (face.Check(PolyHedra -> Corners.Count()))
			{
				data.Insert(PolyHedra::Edge(face.udx[0], face.udx[1]));
				data.Insert(PolyHedra::Edge(face.udx[1], face.udx[2]));
				data.Insert(PolyHedra::Edge(face.udx[2], face.udx[0]));
			}
		}
		BufferWire.Elem.Data(data);*/
		BufferWire.ElemBuffer.DataFull(PolyHedra -> Edges.ToVoid());
	}

	UpdateWireMain = false;
}
void PolyHedraInstanceManager::UpdateWireBufferInst()
{
	BufferWire.InstBuffer.DataFull(InstancesWire.ToVoid());
}
void PolyHedraInstanceManager::DrawWire()
{
	UpdateWireBufferInit();
	UpdateWireBufferMain();
	UpdateWireBufferInst();
	BufferWire.Draw();
}



void PolyHedraInstanceManager::ClearInstances()
{
	InstancesFull.Clear();
	InstancesWire.Clear();
}
void PolyHedraInstanceManager::PlaceInstance(const PolyHedraObjectData & obj)
{
	if (obj.PolyHedra == PolyHedra)
	{
		if (obj.DrawFull)
		{
			InstancesFull.Insert(Instance::Basic3D::Data(obj.Trans));
		}
		if (obj.DrawWire)
		{
			InstancesWire.Insert(Instance::Basic3D::Data(obj.Trans));
		}
	}
}
void PolyHedraInstanceManager::PlaceInstances(const Container::Array<PolyHedraObjectData> & objs)
{
	for (unsigned int i = 0; i < objs.Length(); i++)
	{
		PlaceInstance(objs[i]);
	}
}
