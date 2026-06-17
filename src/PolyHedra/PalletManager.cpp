#include "PolyHedra/PalletManager.hpp"
#include "PolyHedra/Manager.hpp"
#include "PolyHedra/ObjectData.hpp"

#include "Miscellaneous/Container/Array.hpp"
#include "Miscellaneous/Container/Binary.hpp"

#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Graphics/Full/Main/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"

#include "PolyHedra/Skin/Skin.hpp"



PolyHedraPalletManager::~PolyHedraPalletManager()
{ }

PolyHedraPalletManager::PolyHedraPalletManager(::PolyHedra * pallet)
	: Pallet(pallet)
	, DefaultVisibilityFull(true)
	, DefaultVisibilityWire(false)
	, ObjectDatas()
	, InstancesFull()
	, InstancesWire()
	, BufferFull()
	, BufferWire()
	, TextureFull()
	, GraphicsExist(false)
{ }



void PolyHedraPalletManager::RemoveObjects()
{
	for (unsigned int i = 0; i < ObjectDatas.Count(); i++)
	{
		const PolyHedraObjectData * obj = ObjectDatas[i];
		if (obj == nullptr)
		{
			ObjectDatas.RemoveAt(i);
			i--;
		}
		else if (obj -> Remove)
		{
			ObjectDatas.RemoveAt(i);
			delete obj;
			i--;
		}
	}
}

PolyHedraObjectData * PolyHedraPalletManager::MakeObject()
{
	PolyHedraObjectData * obj = new PolyHedraObjectData(this);
	obj -> DrawFull = DefaultVisibilityFull;
	obj -> DrawWire = DefaultVisibilityWire;
	ObjectDatas.Insert(obj);
	return obj;
}
PolyHedraObjectData * PolyHedraPalletManager::CopyObject(const PolyHedraObjectData * other)
{
	PolyHedraObjectData * obj = new PolyHedraObjectData(this);
	*obj = *other;
	ObjectDatas.Insert(obj);
	return obj;
}

PolyHedraObjectData * PolyHedraPalletManager::TryMakeObject(PolyHedraPalletManager * pallet)
{
	if (pallet == nullptr) { return nullptr; }
	return pallet -> MakeObject();
}
PolyHedraObjectData * PolyHedraPalletManager::TryCopyObject(PolyHedraPalletManager * pallet, const PolyHedraObjectData * other)
{
	if (pallet == nullptr) { return nullptr; }
	return pallet -> CopyObject(other);
}



void PolyHedraPalletManager::PutInstance(const PolyHedraObjectData & obj)
{
	if (obj.DrawFull)
	{
		InstancesFull.Insert(obj.ToData());
	}
	if (obj.DrawWire)
	{
		InstancesWire.Insert(obj.ToData());
	}
}
void PolyHedraPalletManager::PutInstance(const PolyHedraObjectData * obj)
{
	if (obj != nullptr)
	{
		PutInstance(*obj);
	}
}
void PolyHedraPalletManager::MakeInstances()
{
	InstancesFull.Clear();
	InstancesWire.Clear();

	for (unsigned int i = 0; i < ObjectDatas.Count(); i++)
	{
		PutInstance(ObjectDatas[i]);
	}

	RemoveObjects();
}



void PolyHedraPalletManager::ChangeMedia(PolyHedraManager & manager)
{
	BufferFull.MainBuffer.Init(manager.BufferLayoutFullMain);
	BufferFull.InstBuffer.Init(manager.BufferLayoutFullInst);
	BufferWire.MainBuffer.Init(manager.BufferLayoutWireMain);
	BufferWire.InstBuffer.Init(manager.BufferLayoutWireInst);
}
void PolyHedraPalletManager::GraphicsCreate()
{
	if (!GraphicsExist)
	{
		BufferFull.Create();
		BufferWire.Create();
		GraphicsExist = true;

		BufferFull.MainBuffer.DataWant = true;
		BufferWire.MainBuffer.DataWant = true;
		BufferWire.ElemBuffer.DataWant = true;
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
	if (Pallet == nullptr) { return; }

	if (BufferFull.MainBuffer.DataWant)
	{
		Pallet -> Calc_Face_Normals();
		Container::Array<PolyHedraFull::Main::Data> data = Pallet -> ToMainData();
		BufferFull.MainBuffer.DataFull(data.ToVoid());

		TextureFull.Delete();
		if (Pallet -> Skins.Count() == 1)
		{
			TextureFull = Pallet -> Skins[0] -> ToTexture();
		}

		BufferFull.MainBuffer.DataWant = false;
	}
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
	if (Pallet == nullptr) { return; }

	if (BufferWire.MainBuffer.DataWant)
	{
		Container::Binary<PolyHedraWire::Main::Data> data;
		for (unsigned int i = 0; i < Pallet -> Corners.Count(); i++)
		{
			data.Insert(PolyHedraWire::Main::Data(Pallet -> Corners[i].Position, ColorF4(1, 1, 1)));
		}
		BufferWire.MainBuffer.DataFull(data.ToVoid());
		BufferWire.MainBuffer.DataWant = false;
	}

	if (BufferWire.ElemBuffer.DataWant)
	{
		BufferWire.ElemBuffer.DataFull(Pallet -> Edges.ToVoid());
		BufferWire.ElemBuffer.DataWant = false;
	}
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
