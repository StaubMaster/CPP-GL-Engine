#ifndef  POLYHEDRA_DATA_HPP
# define POLYHEDRA_DATA_HPP

# include "PolyHedra.hpp"

# include "ValueType/Point2D.hpp"
# include "ValueType/Point3D.hpp"

struct PolyHedra::Corner
{
	Point3D	Position;
	Point3D	Normal;
	Corner();
	Corner(Point3D pos);
};
struct PolyHedra::FaceCorner
{
	unsigned int Udx;
	FaceCorner();
	FaceCorner(unsigned int udx);
};
struct PolyHedra::Face
{
	FaceCorner Corner0;
	FaceCorner Corner1;
	FaceCorner Corner2;
	Point3D	Normal;
	Face();
	Face(FaceCorner c0, FaceCorner c1, FaceCorner c2);
};

#endif