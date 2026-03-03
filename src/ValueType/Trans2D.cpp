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
	Pos += (Rot * move);
}
void Trans2D::Spin(Angle2D spin)
{
	Rot += spin;
}
void Trans2D::Change(Point2D move, Angle2D spin)
{
	Move(move);
	Spin(spin);
}
void Trans2D::Change(Trans2D trans)
{
	Change(trans.Pos, trans.Rot);
}





Point2D Trans2D::operator*(Point2D pos) const { return (Rot * pos) + Pos; }
//Angle2D Trans2D::operator*(Angle2D rot) const { return Rot.rotateBack(rot); }
//Trans2D Trans2D::operator*(Trans2D trans) const { }
Ray2D Trans2D::operator*(Ray2D ray) const
{
	return Ray2D(
		(Rot * ray.Pos) + Pos,
		(Rot * ray.Dir)
	);
}

Point2D Trans2D::operator/(Point2D pos) const { return Rot / (pos - Pos); }
//Angle2D Trans2D::operator/(Angle2D rot) const { return Rot.rotateFore(rot); }
//Trans2D Trans2D::operator/(Trans2D trans) const;
Ray2D Trans2D::operator/(Ray2D ray) const
{
	return Ray2D(
		Rot / (ray.Pos - Pos),
		Rot / (ray.Dir)
	);
}
