#include "ValueType/Trans3D.hpp"



Trans3D::Trans3D() :
	Pos(),
	Rot()
{ }
Trans3D::Trans3D(Point3D pos, Angle3D rot) :
	Pos(pos),
	Rot(rot)
{ }
Trans3D::~Trans3D()
{ }

Trans3D::Trans3D(const Trans3D & other) :
	Pos(other.Pos),
	Rot(other.Rot)
{ }
Trans3D & Trans3D::operator=(const Trans3D & other)
{
	Pos = other.Pos;
	Rot = other.Rot;
	return *this;
}



void Trans3D::MoveFlatX(Point3D move)
{
	Angle3D a(Rot.X, Angle(), Angle());
	a.CalcBack();
	Pos += a.rotate(move);
	//Pos = Pos + (Angle3D(Rot.X, 0, 0).rotate(move));
}
void Trans3D::SpinFlatX(Angle3D spin)
{
	Rot += spin;
	//Rot.X = Rot.X + spin.X;
	//Rot.Y = Rot.Y + spin.Y;
	//Rot.Z = 0;
}
void Trans3D::TransformFlatX(Point3D move, Angle3D spin)
{
	MoveFlatX(move);
	SpinFlatX(spin);
}
