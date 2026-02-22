#include "ValueType/Trans2D.hpp"
#include "ValueType/Ray2D.hpp"



Trans2D::Trans2D() :
	Pos(),
	Rot()
{ }
Trans2D::Trans2D(Point2D pos, Angle2D rot) :
	Pos(pos),
	Rot(rot)
{ }
Trans2D::~Trans2D()
{ }

Trans2D::Trans2D(const Trans2D & other) :
	Pos(other.Pos),
	Rot(other.Rot)
{ }
Trans2D & Trans2D::operator=(const Trans2D & other)
{
	Pos = other.Pos;
	Rot = other.Rot;
	return *this;
}



void Trans2D::Move(Point2D move)
{
	Pos += Rot.rotateBack(move);
}
void Trans2D::Spin(Angle2D spin)
{
	Rot += spin;
}
void Trans2D::Transform(Point2D move, Angle2D spin)
{
	Move(move);
	Spin(spin);
}





Point2D Trans2D::Transform0(Point2D pos) const { return Rot.rotateBack(pos) + Pos; }
//Angle2D Trans2D::Transform0(Angle2D rot) const { return Rot.rotateBack(rot); }
//Trans2D Trans2D::oTransform0(Trans2D trans) const { }
Ray2D Trans2D::Transform0(Ray2D ray) const
{
	return Ray2D(
		Rot.rotateBack(ray.Pos) + Pos,
		Rot.rotateBack(ray.Dir)
	);
}

Point2D Trans2D::Transform1(Point2D pos) const { return Rot.rotateFore(pos - Pos); }
//Angle2D Trans2D::Transform1(Angle2D rot) const { return Rot.rotateFore(rot); }
//Trans2D Trans2D::Transform1(Trans2D trans) const;
Ray2D Trans2D::Transform1(Ray2D ray) const
{
	return Ray2D(
		Rot.rotateFore(ray.Pos - Pos),
		Rot.rotateFore(ray.Dir)
	);
}
