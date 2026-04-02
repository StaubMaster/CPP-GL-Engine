#include "ValueType/Transformation3D.hpp"
#include "ValueType/Matrix4x4.hpp"

Transformation3D::~Transformation3D()
{ }
Transformation3D::Transformation3D()
	: Position()
	, Rotation()
{ }

Transformation3D::Transformation3D(const Transformation3D & other)
	: Position(other.Position)
	, Rotation(other.Rotation)
{ }
Transformation3D & Transformation3D::operator=(const Transformation3D & other)
{
	Position = other.Position;
	Rotation = other.Rotation;
	return *this;
}

Transformation3D::Transformation3D(Point3D pos)
	: Position(pos)
	, Rotation()
{ }
Transformation3D::Transformation3D(EulerAngle3D rot)
	: Position()
	, Rotation(rot)
{ }
Transformation3D::Transformation3D(Point3D pos, EulerAngle3D rot)
	: Position(pos)
	, Rotation(rot)
{ }



Matrix4x4 Transformation3D::ToMatrixForward() const
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat = mat * Matrix4x4::Position(+Position);
	mat = mat * Matrix4x4::Rotation(Rotation);
	return mat;
}
Matrix4x4 Transformation3D::ToMatrixReverse() const
{
	Matrix4x4 mat = Matrix4x4::Identity();
	mat = mat * Matrix4x4::Position(-Position);
	mat = mat / Matrix4x4::Rotation(Rotation);
	return ~mat;
}



Point3D Transformation3D::Forward(Point3D p) const
{
	return Rotation.Forward(p) + Position;
}
Point3D Transformation3D::Reverse(Point3D p) const
{
	return Rotation.Reverse(p - Position);
}
