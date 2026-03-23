#include "ValueType/Intersect.hpp"
#include "DataInclude.hpp"



bool IsIntersecting(
	const Ray2D & ray,
	const Line2D & line
)
{
	Point2D perp(-ray.Dir.Y, +ray.Dir.X);
	Point2D diff = line.Pos1 - line.Pos0;

	float dot = Point2D::dot(diff, perp);
	if (dot == 0.0f) { return false; }

	Point2D rel = ray.Pos - line.Pos0;
	float line_t = rel.dot(perp) / dot;
	if (line_t < 0.0f || line_t > 1.0f) { return false; }

	float ray_t = Point2D::cross(diff, rel) / dot;
	if (ray_t < 0.0f) { return false; }

	return true;
}

bool IsIntersecting(
	const Line2D & line0,
	const Line2D & line1
)
{
	Point2D diff0 = line0.Pos1 - line0.Pos0;
	Point2D perp(-diff0.Y, +diff0.X);
	Point2D diff1 = line1.Pos1 - line1.Pos0;

	float dot = Point2D::dot(diff1, perp);
	if (dot == 0.0f) { return false; }

	Point2D rel = line0.Pos0 - line1.Pos0;

	float line1_t = rel.dot(perp) / dot;
	if (line1_t < 0.0f || line1_t > 1.0f) { return false; }

	float line0_t = Point2D::cross(diff1, rel) / dot;
	if (line0_t < 0.0f || line0_t > 1.0f) { return false; }

	return true;
}

bool Intersection(const Line2D & line0, const Line2D & line1, Point2D & ret)
{
	Point2D diff0 = line0.Pos1 - line0.Pos0;
	Point2D perp(-diff0.Y, +diff0.X);
	Point2D diff1 = line1.Pos1 - line1.Pos0;

	float dot = Point2D::dot(diff1, perp);
	if (dot == 0.0f) { return false; }

	Point2D rel = line0.Pos0 - line1.Pos0;

	float line1_t = rel.dot(perp) / dot;
	if (line1_t < 0.0f || line1_t > 1.0f) { return false; }

	float line0_t = Point2D::cross(diff1, rel) / dot;
	if (line0_t < 0.0f || line0_t > 1.0f) { return false; }

	ret = line0.Pos0 + (diff0 * line0_t);
	return true;
}
