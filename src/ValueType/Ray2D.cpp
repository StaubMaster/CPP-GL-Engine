#include "ValueType/Ray2D.hpp"
#include "ValueType/Line2D.hpp"

//#include <math.h>



Ray2D::~Ray2D() { }

Ray2D::Ray2D()
	: Pos()
	, Dir()
{ }
Ray2D::Ray2D(Point2D pos, Point2D dir)
	: Pos(pos)
	, Dir(dir)
{ }

Ray2D::Ray2D(const Ray2D & other)
	: Pos(other.Pos)
	, Dir(other.Dir)
{ }
Ray2D & Ray2D::operator=(const Ray2D & other)
{
	Pos = other.Pos;
	Dir = other.Dir;
	return *this;
}



Point2D Ray2D::ToPoint(float scalar) const
{
	return Pos + (Dir * scalar);
}
Line2D Ray2D::ToLine(float scalar) const
{
	return Line2D(Pos, Pos + (Dir * scalar));
}
Line2D Ray2D::ToLine(float scalar0, float scalar1) const
{
	return Line2D(Pos + (Dir * scalar0), Pos + (Dir * scalar1));
}



//Ray2D::Interval::Interval(const Ray2D & ray, float inter = NAN, int index = -1) :
//	Ray(ray), Inter(inter), Index(index) { }

/*Ray2D::Interval Ray2D::Ray_Point(Point2D p)
{
	float dot = Point2D::dot(Dir, Pos - p);
	float sqr = Dir.length2();
	return Ray2D::Interval(*this, -(dot / sqr));
}*/
