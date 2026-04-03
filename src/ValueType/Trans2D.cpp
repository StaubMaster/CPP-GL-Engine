#include "ValueType/Trans2D.hpp"
#include "ValueType/Ray2D.hpp"



Trans2D::~Trans2D() { }

Trans2D::Trans2D()
	: Pos()
	, Rot()
{ }
Trans2D::Trans2D(Point2D pos)
	: Pos(pos)
	, Rot()
{ }
Trans2D::Trans2D(Point2D pos, Angle2D rot)
	: Pos(pos)
	, Rot(rot)
{ }

Trans2D::Trans2D(const Trans2D & other)
	: Pos(other.Pos)
	, Rot(other.Rot)
{ }
Trans2D & Trans2D::operator=(const Trans2D & other)
{
	Pos = other.Pos;
	Rot = other.Rot;
	return *this;
}



Point2D Trans2D::forward(Point2D p) const { return (Rot * p) + Pos; }
Point2D Trans2D::reverse(Point2D p) const { return Rot / (p - Pos); }

Ray2D Trans2D::forward(Ray2D ray) const
{
	return Ray2D(
		forward(ray.Pos),
		(Rot * ray.Dir)
	);
}
Ray2D Trans2D::reverse(Ray2D ray) const
{
	return Ray2D(
		reverse(ray.Pos),
		(Rot / ray.Dir)
	);
}
