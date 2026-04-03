#include "ValueType/Trans3D.hpp"
#include "ValueType/Matrix4x4.hpp"



Trans3D::~Trans3D() { }

Trans3D::Trans3D()
	: Position()
	, Rotation()
{ }
Trans3D::Trans3D(Point3D pos)
	: Position(pos)
	, Rotation()
{ }
Trans3D::Trans3D(EulerAngle3D rot)
	: Position()
	, Rotation(rot)
{ }
Trans3D::Trans3D(Point3D pos, EulerAngle3D rot)
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





Point3D Trans3D::forward(Point3D p) const
{
	return Rotation.forward(p) + Position;
}
Point3D Trans3D::reverse(Point3D p) const
{
	return Rotation.reverse(p - Position);
}



Matrix4x4 Trans3D::ToMatrixForward() const
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat = mat * Matrix4x4::Position(+Position);
	mat = mat * Matrix4x4::Rotation(Rotation);
	return mat;
}
Matrix4x4 Trans3D::ToMatrixReverse() const
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat = mat * Matrix4x4::Position(-Position);
	mat = mat / Matrix4x4::Rotation(Rotation);
	return ~mat;
}
