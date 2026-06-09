#include "PolyHedra/PalletManager.hpp"
#include "PolyHedra/Manager.hpp"
#include "PolyHedra/ObjectData.hpp"

#include "Miscellaneous/Container/Array.hpp"
#include "Miscellaneous/Container/Binary.hpp"

#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Graphics/Full/Main/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"



PolyHedraPalletManager::~PolyHedraPalletManager()
{ }
PolyHedraPalletManager::PolyHedraPalletManager()
	: Pallet(nullptr)
	, DefaultVisibilityFull(true)
	, DefaultVisibilityWire(false)
	, InstancesFull()
	, InstancesWire()
	, BufferFullMainBound(false)
	, BufferWireMainBound(false)
	, BufferFull()
	, BufferWire()
	, TextureFull()
	, GraphicsExist(false)
{ }
/*PolyHedraPalletManager::PolyHedraPalletManager(const PolyHedraPalletManager & other)
	: Pallet(other.Pallet)
	, DefaultVisibilityFull(other.DefaultVisibilityFull)
	, DefaultVisibilityWire(other.DefaultVisibilityWire)
	, InstancesFull(other.InstancesFull)
	, InstancesWire(other.InstancesWire)
	, BufferFullMainBound(other.BufferFullMainBound)
	, BufferWireMainBound(other.BufferWireMainBound)
	, BufferFull(other.BufferFull)
	, BufferWire(other.BufferWire)
	, TextureFull(other.TextureFull)
	, GraphicsExist(other.GraphicsExist)
{ }*/
/*PolyHedraPalletManager & PolyHedraPalletManager::operator=(const PolyHedraPalletManager & other)
{
	Pallet = other.Pallet;
	DefaultVisibilityFull = other.DefaultVisibilityFull;
	DefaultVisibilityWire = other.DefaultVisibilityWire;
	InstancesFull = other.InstancesFull;
	InstancesWire = other.InstancesWire;
	BufferFullMainBound = other.BufferFullMainBound;
	BufferWireMainBound = other.BufferWireMainBound;
	BufferFull = other.BufferFull;
	BufferWire = other.BufferWire;
	TextureFull = other.TextureFull;
	GraphicsExist = other.GraphicsExist;
	return *this;
}*/

PolyHedraPalletManager::PolyHedraPalletManager(::PolyHedra * pallet)
	: Pallet(pallet)
	, DefaultVisibilityFull(true)
	, DefaultVisibilityWire(false)
	, InstancesFull()
	, InstancesWire()
	, BufferFullMainBound(false)
	, BufferWireMainBound(false)
	, BufferFull()
	, BufferWire()
	, TextureFull()
	, GraphicsExist(false)
{ }
void PolyHedraPalletManager::Change(::PolyHedra * pallet)
{
	Pallet = pallet;
	BufferFullMainBound = false;
	BufferWireMainBound = false;
}



void PolyHedraPalletManager::ClearInstances()
{
	InstancesFull.Clear();
	InstancesWire.Clear();
}
void PolyHedraPalletManager::PlaceInstance(const PolyHedraObjectData & obj)
{
	if (obj.PalletManager == this)
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
void PolyHedraPalletManager::PlaceInstances(const Container::Array<PolyHedraObjectData> & objs)
{
	for (unsigned int i = 0; i < objs.Length(); i++)
	{
		PlaceInstance(objs[i]);
	}
}



void PolyHedraPalletManager::ChangeMedia(PolyHedraManager & manager)
{
	BufferFull.MainBuffer.AttributeLayout = &manager.BufferLayoutFullMain;
	BufferFull.InstBuffer.AttributeLayout = &manager.BufferLayoutFullInst;
	BufferWire.MainBuffer.AttributeLayout = &manager.BufferLayoutWireMain;
	BufferWire.InstBuffer.AttributeLayout = &manager.BufferLayoutWireInst;
}
void PolyHedraPalletManager::GraphicsCreate()
{
	if (!GraphicsExist)
	{
		// do this when Buffer.Create() ?
		BufferFull.MainBuffer.AttributesBound = false;
		BufferFull.InstBuffer.AttributesBound = false;
		BufferWire.MainBuffer.AttributesBound = false;
		BufferWire.InstBuffer.AttributesBound = false;

		BufferFull.Create();
		BufferWire.Create();
		GraphicsExist = true;
	}
}
void PolyHedraPalletManager::GraphicsDelete()
{
	if (GraphicsExist)
	{
		BufferFull.Delete();
		BufferWire.Delete();
		GraphicsExist = false;
	}
}



void PolyHedraPalletManager::UpdateFullBufferMain()
{
	if (!(!BufferFullMainBound && Pallet != nullptr && GraphicsExist)) { return; }

	{
		Pallet -> Calc_Face_Normals();
		Container::Array<PolyHedraFull::Main::Data> data = Pallet -> ToMainData();
		BufferFull.MainBuffer.DataFull(data.ToVoid());
	}

	if (Pallet -> Skin != nullptr)
	{
		Skin2DA * skin = (Skin2DA*)(Pallet -> Skin);
		skin -> ToTexture(TextureFull);
	}
	else
	{
		TextureFull.Delete();
	}

	BufferFullMainBound = true;
}
void PolyHedraPalletManager::DrawFull()
{
	if (!GraphicsExist) { return; }
	BufferFull.MainBuffer.Update();
	BufferFull.InstBuffer.Update();
	UpdateFullBufferMain();
	BufferFull.InstBuffer.DataFull(InstancesFull.ToVoid());
	TextureFull.Bind();
	BufferFull.Draw();
}

void PolyHedraPalletManager::UpdateWireBufferMain()
{
	if (!(!BufferWireMainBound && Pallet != nullptr && GraphicsExist)) { return; }

	{
		Container::Binary<PolyHedraWire::Main::Data> data;
		for (unsigned int i = 0; i < Pallet -> Corners.Count(); i++)
		{
			data.Insert(PolyHedraWire::Main::Data(Pallet -> Corners[i].Position, ColorF4(1, 1, 1)));
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
		BufferWire.ElemBuffer.DataFull(Pallet -> Edges.ToVoid());
	}

	BufferWireMainBound = true;
}
void PolyHedraPalletManager::DrawWire()
{
	if (!GraphicsExist) { return; }
	BufferWire.MainBuffer.Update();
	BufferWire.InstBuffer.Update();
	UpdateWireBufferMain();
	BufferWire.InstBuffer.DataFull(InstancesWire.ToVoid());
	BufferWire.Draw();
}
