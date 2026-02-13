#ifndef  RAY_2D_HPP
# define RAY_2D_HPP

# include "Point2D.hpp"

struct Ray2D
{
	public:
	Point2D Pos;
	Point2D Dir;

	public:
	Ray2D();
	Ray2D(Point2D pos, Point2D dir);

	public:
	class Interval
	{
		public:
		const Ray2D & Ray;
		const float Inter;
		const int Index;
		public:
		Interval(const Ray2D & ray, float inter, int index);
		public:
		Point2D ToPoint() const;
	};

	public:
	Interval Ray_Point(Point2D p);
};

#endif