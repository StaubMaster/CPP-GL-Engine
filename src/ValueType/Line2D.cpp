#include "ValueType/Line2D.hpp"
#include "ValueType/Ray2D.hpp"



Line2D::~Line2D() { }

Line2D::Line2D()
	: Origin()
	, Target()
{ }
Line2D::Line2D(VectorF2 origin, VectorF2 target)
	: Origin(origin)
	, Target(target)
{ }

Line2D::Line2D(const Line2D & other)
	: Origin(other.Origin)
	, Target(other.Target)
{ }
Line2D & Line2D::operator=(const Line2D & other)
{
	Origin = other.Origin;
	Target = other.Target;
	return *this;
}

Line2D::Line2D(const Ray2D & ray)
	: Origin(ray.Pos)
	, Target(ray.Pos + ray.Dir)
{ }



Line2D Line2D::Reverse() const
{
	return Line2D(Target, Origin);
}

VectorF2 Line2D::Differance() const
{
	return (Target - Origin);
}
float Line2D::Length() const
{
	return Differance().length();
}

VectorF2 Line2D::Middle() const
{
	return (Origin + Target) / 2;
}
VectorF2 Line2D::Normal() const
{
	return Differance().cross(1.0f).normalize();
}
