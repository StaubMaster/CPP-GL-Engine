#include "PolyHedra/ObjectData.hpp"



PolyHedraObjectData::~PolyHedraObjectData()
{ }
PolyHedraObjectData::PolyHedraObjectData()
	: Remove(false)
	, DrawFull(true)
	, DrawWire(false)
	, PalletManager(nullptr)
	, Trans()
{ }
PolyHedraObjectData::PolyHedraObjectData(const PolyHedraObjectData & other)
	: Remove(other.Remove)
	, DrawFull(other.DrawFull)
	, DrawWire(other.DrawWire)
	, PalletManager(other.PalletManager)
	, Trans(other.Trans)
{ }
PolyHedraObjectData & PolyHedraObjectData::operator=(const PolyHedraObjectData & other)
{
	Remove = other.Remove;
	DrawFull = other.DrawFull;
	DrawWire = other.DrawWire;
	PalletManager = other.PalletManager;
	Trans = other.Trans;
	return *this;
}



PolyHedraObjectData::PolyHedraObjectData(::PolyHedraPalletManager * manager)
	: Remove(false)
	, DrawFull(true)
	, DrawWire(false)
	, PalletManager(manager)
	, Trans()
{ }
