#include "ValueType/Line3D.hpp"
#include "ValueType/Ray3D.hpp"



Line3D::~Line3D() { }

Line3D::Line3D()
	: Origin()
	, Target()
{ }
Line3D::Line3D(VectorF3 origin, VectorF3 target)
	: Origin(origin)
	, Target(target)
{ }

Line3D::Line3D(const Line3D & other)
	: Origin(other.Origin)
	, Target(other.Target)
{ }
Line3D & Line3D::operator=(const Line3D & other)
{
	Origin = other.Origin;
	Target = other.Target;
	return *this;
}

Line3D::Line3D(const Ray3D & ray)
	: Origin(ray.Pos)
	, Target(ray.Pos + ray.Dir)
{ }



Line3D Line3D::Reverse() const
{
	return Line3D(Target, Origin);
}

VectorF3 Line3D::Differance() const
{
	return (Target - Origin);
}
float Line3D::Length() const
{
	return Differance().length();
}

VectorF3 Line3D::Middle() const
{
	return (Origin + Target) / 2;
}
