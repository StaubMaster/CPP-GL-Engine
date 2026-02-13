#include "ValueType/Ray2D.hpp"
#include "ValueType/Point2D.hpp"

#include <math.h>



Ray2D::Ray2D() :
	Pos(), Dir() { }
Ray2D::Ray2D(Point2D pos, Point2D dir) :
	Pos(pos), Dir(dir) { }



Ray2D::Interval::Interval(const Ray2D & ray, float inter = NAN, int index = -1) :
	Ray(ray), Inter(inter), Index(index) { }



Ray2D::Interval Ray2D::Ray_Point(Point2D p)
{
	float dot = Point2D::dot(Dir, Pos - p);
	float sqr = Dir.length2();
	return Ray2D::Interval(*this, -(dot / sqr));
}
