#ifndef  POLYHEDRA_MAIN_DATA_HPP
# define POLYHEDRA_MAIN_DATA_HPP

# include "ValueType/Point3D.hpp"

namespace PolyHedra_Main
{
struct Data
{
	Point3D	Position;
	Point3D	Normal;
	Point3D	Texture;

	//PolyHedra_MainData();
	//~PolyHedra_MainData();
};
};

#endif