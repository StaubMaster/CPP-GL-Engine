#include "ValueType/Line2D.hpp"



Line2D::~Line2D() { }

Line2D::Line2D()
	: Pos0()
	, Pos1()
{ }
Line2D::Line2D(Point2D pos0, Point2D pos1)
	: Pos0(pos0)
	, Pos1(pos1)
{ }

Line2D::Line2D(const Line2D & other)
	: Pos0(other.Pos0)
	, Pos1(other.Pos1)
{ }
Line2D & Line2D::operator=(const Line2D & other)
{
	Pos0 = other.Pos0;
	Pos1 = other.Pos1;
	return *this;
}
