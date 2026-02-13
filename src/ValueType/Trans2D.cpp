#include "ValueType/Trans2D.hpp"



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
