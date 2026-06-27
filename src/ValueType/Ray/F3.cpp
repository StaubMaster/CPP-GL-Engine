#include "ValueType/Ray/F3.hpp"
#include "ValueType/Vector/F3.hpp"

#include <math.h>



RayF3::RayF3(const VectorF3 & pos, const VectorF3 & dir)
	: Pos(pos)
	, Dir(dir)
{ }



RayF3::Interval::Interval(const RayF3 & ray, float inter = NAN, int index = -1)
	: Ray(ray)
	, Inter(inter)
	, Index(index)
{ }



RayF3::Interval RayF3::Ray_Point(VectorF3 p)
{
	float dot = VectorF3::dot(Dir, Pos - p);
	float sqr = Dir.length2();
	return RayF3::Interval(*this, -(dot / sqr));
}
