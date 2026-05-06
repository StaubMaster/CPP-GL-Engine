#ifndef  POLYHEDRA_OBJECT_DATA_HPP
# define POLYHEDRA_OBJECT_DATA_HPP

class PolyHedra;
# include "ValueType/Trans3D.hpp"

struct PolyHedraObjectData
{
	bool	Remove; // allways needed
	bool	DrawFull; // at least Draw allways needed
	bool	DrawWire;

	// store InstanceManager as Key ?
	// use Key = nullptr as Remove ?

	::PolyHedra *	PolyHedra; // Main "Key"
	Trans3D			Trans; // Inst Data

	~PolyHedraObjectData();
	PolyHedraObjectData();
	PolyHedraObjectData(const PolyHedraObjectData & other);
	PolyHedraObjectData & operator=(const PolyHedraObjectData & other);

	PolyHedraObjectData(::PolyHedra * polyhedra);
};

#endif