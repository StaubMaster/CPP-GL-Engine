#ifndef  POLYHEDRA_MAIN_DATA_HPP
# define POLYHEDRA_MAIN_DATA_HPP

# include "DataStruct/Point3D.hpp"
# include "DataStruct/Point2D.hpp"

namespace PolyHedra_Main
{
struct Data
{
	Point3D	Position;
	Point3D	Normal;
	Point2D	Texture;

	//PolyHedra_MainData();
	//~PolyHedra_MainData();
};
};

#endif