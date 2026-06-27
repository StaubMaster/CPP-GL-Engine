#ifndef  POLYHEDRA_OBJECT_DATA_HPP
# define POLYHEDRA_OBJECT_DATA_HPP

class PolyHedraPalletManager;
# include "ValueType/Trans/3D.hpp"

namespace Instance { namespace Basic3D { struct Data; }; };

struct PolyHedraObjectData
{
	bool	Remove; // allways needed
	bool	DrawFull; // at least Draw allways needed
	bool	DrawWire;

	::PolyHedraPalletManager *	PalletManager;
	Trans3D						Trans; // Inst Data

	~PolyHedraObjectData();
	PolyHedraObjectData();
	PolyHedraObjectData(const PolyHedraObjectData & other);
	PolyHedraObjectData & operator=(const PolyHedraObjectData & other);

	PolyHedraObjectData(::PolyHedraPalletManager * manager);

	Instance::Basic3D::Data		ToData() const;
};

#endif