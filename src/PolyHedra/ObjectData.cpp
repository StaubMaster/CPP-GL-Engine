#include "PolyHedra/ObjectData.hpp"



PolyHedraObjectData::~PolyHedraObjectData()
{ }
PolyHedraObjectData::PolyHedraObjectData()
	: PolyHedra(nullptr)
	, Trans()
	, Remove(false)
	, DrawFull(true)
	, DrawWire(false)
{ }
PolyHedraObjectData::PolyHedraObjectData(const PolyHedraObjectData & other)
	: PolyHedra(other.PolyHedra)
	, Trans(other.Trans)
	, Remove(other.Remove)
	, DrawFull(other.DrawFull)
	, DrawWire(other.DrawWire)
{ }
PolyHedraObjectData & PolyHedraObjectData::operator=(const PolyHedraObjectData & other)
{
	PolyHedra = other.PolyHedra;
	Trans = other.Trans;
	Remove = other.Remove;
	DrawFull = other.DrawFull;
	DrawWire = other.DrawWire;
	return *this;
}



PolyHedraObjectData::PolyHedraObjectData(::PolyHedra * polyhedra)
	: PolyHedra(polyhedra)
	, Trans()
	, Remove(false)
	, DrawFull(true)
	, DrawWire(false)
{ }
PolyHedraObjectData::PolyHedraObjectData(::PolyHedra * polyhedra, Trans3D trans)
	: PolyHedra(polyhedra)
	, Trans(trans)
	, Remove(false)
	, DrawFull(true)
	, DrawWire(false)
{ }
