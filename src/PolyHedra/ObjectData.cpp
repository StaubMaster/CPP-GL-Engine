#include "PolyHedra/ObjectData.hpp"



PolyHedraObjectData::~PolyHedraObjectData()
{ }
PolyHedraObjectData::PolyHedraObjectData()
	: Remove(false)
	, DrawFull(true)
	, DrawWire(false)
	, PolyHedra(nullptr)
	, Trans()
{ }
PolyHedraObjectData::PolyHedraObjectData(const PolyHedraObjectData & other)
	: Remove(other.Remove)
	, DrawFull(other.DrawFull)
	, DrawWire(other.DrawWire)
	, PolyHedra(other.PolyHedra)
	, Trans(other.Trans)
{ }
PolyHedraObjectData & PolyHedraObjectData::operator=(const PolyHedraObjectData & other)
{
	Remove = other.Remove;
	DrawFull = other.DrawFull;
	DrawWire = other.DrawWire;
	PolyHedra = other.PolyHedra;
	Trans = other.Trans;
	return *this;
}



PolyHedraObjectData::PolyHedraObjectData(::PolyHedra * polyhedra)
	: Remove(false)
	, DrawFull(true)
	, DrawWire(false)
	, PolyHedra(polyhedra)
	, Trans()
{ }
