#include "ValueType/Trans3D.hpp"
#include "ValueType/Matrix4x4.hpp"



Trans3D::~Trans3D() { }

Trans3D::Trans3D()
	: Position()
	, Rotation()
{ }
Trans3D::Trans3D(VectorF3 pos)
	: Position(pos)
	, Rotation()
{ }
Trans3D::Trans3D(EulerAngle3D rot)
	: Position()
	, Rotation(rot)
{ }
Trans3D::Trans3D(VectorF3 pos, EulerAngle3D rot)
	: Position(pos)
	, Rotation(rot)
{ }

Trans3D::Trans3D(const Trans3D & other)
	: Position(other.Position)
	, Rotation(other.Rotation)
{ }
Trans3D & Trans3D::operator=(const Trans3D & other)
{
	Position = other.Position;
	Rotation = other.Rotation;
	return *this;
}





VectorF3 Trans3D::forward(VectorF3 p) const
{
	return Rotation.forward(p) + Position;
}
VectorF3 Trans3D::reverse(VectorF3 p) const
{
	return Rotation.reverse(p - Position);
}
