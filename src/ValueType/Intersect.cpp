#include "ValueType/Intersect.hpp"
#include "DataInclude.hpp"



bool IsIntersecting(const Ray2D & ray, const Line2D & line)
{
	Point2D perp(-ray.Dir.Y, +ray.Dir.X);
	Point2D diff = line.Pos1 - line.Pos0;

	float dot = Point2D::dot(diff, perp);
	if (dot == 0.0f) { return false; }

	Point2D rel = ray.Pos - line.Pos0;
	float line_t = rel.dot(perp) / dot;
	if (line_t < 0.0f || line_t > 1.0f) { return false; }

	float ray_t = diff.cross(rel) / dot;
	if (ray_t < 0.0f) { return false; }

	return true;
}
