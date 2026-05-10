#include "ValueType/Trans2D.hpp"
#include "ValueType/Ray2D.hpp"



Trans2D::~Trans2D() { }

Trans2D::Trans2D()
	: Pos()
	, Rot()
{ }
Trans2D::Trans2D(VectorF2 pos)
	: Pos(pos)
	, Rot()
{ }
Trans2D::Trans2D(VectorF2 pos, Angle rot)
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



VectorF2 Trans2D::forward(VectorF2 p) const { return Rot.forward(p) + Pos; }
VectorF2 Trans2D::reverse(VectorF2 p) const { return Rot.reverse(p - Pos); }

Ray2D Trans2D::forward(Ray2D ray) const
{
	return Ray2D(
		forward(ray.Pos),
		Rot.forward(ray.Dir)
	);
}
Ray2D Trans2D::reverse(Ray2D ray) const
{
	return Ray2D(
		reverse(ray.Pos),
		Rot.reverse(ray.Dir)
	);
}
