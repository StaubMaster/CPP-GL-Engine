#ifndef  RAY_2D_HPP
# define RAY_2D_HPP

# include "ValueType/Vector/F2.hpp"

struct Line2D;

struct Ray2D
{
	public:
	VectorF2	Pos;
	VectorF2	Dir;

	public:
	~Ray2D();

	Ray2D();
	Ray2D(VectorF2 pos, VectorF2 dir);

	Ray2D(const Ray2D & other);
	Ray2D & operator=(const Ray2D & other);

	Ray2D(const Line2D & line);

	VectorF2	ToPoint(float scalar) const;
	Line2D		ToLine(float scalar) const;
	Line2D		ToLine(float scalar0, float scalar1) const;

	VectorF2	Normal() const;

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
//		VectorF2 ToPoint() const;
//	};
//
//	public:
//	Interval Ray_Point(VectorF2 p);
};

#endif