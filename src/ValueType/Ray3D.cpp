#include "ValueType/Ray3D.hpp"
#include "ValueType/Vector/F3.hpp"

#include <math.h>



Ray3D::Ray3D() :
	Pos(), Dir() { }
Ray3D::Ray3D(VectorF3 pos, VectorF3 dir) :
	Pos(pos), Dir(dir) { }



Ray3D::Interval::Interval(const Ray3D & ray, float inter = NAN, int index = -1) :
	Ray(ray), Inter(inter), Index(index) { }



Ray3D::Interval Ray3D::Ray_Point(VectorF3 p)
{
	float dot = VectorF3::dot(Dir, Pos - p);
	float sqr = Dir.length2();
	return Ray3D::Interval(*this, -(dot / sqr));
}
