#ifndef  RAY_2D_HPP
# define RAY_2D_HPP

# include "ValueType/Point2D.hpp"

struct Line2D;

struct Ray2D
{
	public:
	Point2D Pos;
	Point2D Dir;

	public:
	~Ray2D();

	Ray2D();
	Ray2D(Point2D pos, Point2D dir);

	Ray2D(const Ray2D & other);
	Ray2D & operator=(const Ray2D & other);

	Point2D ToPoint(float scalar) const;
	Line2D ToLine(float scalar) const;
	Line2D ToLine(float scalar0, float scalar1) const;

//	public:
//	class Interval
//	{
//		public:
//		const Ray2D & Ray;
//		const float Inter;
//		const int Index;
//		public:
//		Interval(const Ray2D & ray, float inter, int index);
//		public:
//		Point2D ToPoint() const;
//	};
//
//	public:
//	Interval Ray_Point(Point2D p);
};

#endif