#include "PolyHedra/Data.hpp"



PolyHedra::Corner::Corner()
	: Position()
{ }
PolyHedra::Corner::Corner(Point3D pos)
	: Position(pos)
{ }



PolyHedra::Face::Face()
	: udx{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }
	, Normal()
{ }
PolyHedra::Face::Face(unsigned int u0, unsigned int u1, unsigned int u2)
	: udx{ u0, u1, u2 }
	, Normal()
{ }
bool PolyHedra::Face::Check(unsigned int count) const
{
	return (udx[0] < count &&
			udx[1] < count &&
			udx[2] < count);
}



bool PolyHedra::Edge::Check(unsigned int count) const
{
	return (udx[0] < count &&
			udx[1] < count);
}
PolyHedra::Edge::Edge()
	: udx{ 0xFFFFFFFF, 0xFFFFFFFF }
{ }
PolyHedra::Edge::Edge(unsigned int u0, unsigned int u1)
	: udx{ u0, u1 }
{ }
