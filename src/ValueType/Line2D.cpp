#include "ValueType/Line2D.hpp"
#include "ValueType/Ray2D.hpp"



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

Line2D::Line2D(const Ray2D & ray)
	: Pos0(ray.Pos)
	, Pos1(ray.Pos + ray.Dir)
{ }



Line2D Line2D::Reverse() const
{
	return Line2D(Pos1, Pos0);
}

Point2D Line2D::Differance() const
{
	return (Pos1 - Pos0);
}
float Line2D::Length() const
{
	return Differance().length();
}

Point2D Line2D::Normal() const
{
	return Differance().perpendicular0().normalize();
}
Point2D Line2D::Middle() const
{
	return (Pos0 + Pos1) / 2;
}
