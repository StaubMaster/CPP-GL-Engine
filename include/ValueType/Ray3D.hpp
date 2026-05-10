#ifndef  RAY_3D_HPP
# define RAY_3D_HPP

# include "ValueType/Vector/F3.hpp"

struct Ray3D
{
	public:
	VectorF3 Pos;
	VectorF3 Dir;

	public:
	Ray3D();
	Ray3D(VectorF3 pos, VectorF3 dir);

	public:
	class Interval
	{
		public:
		const Ray3D & Ray;
		const float Inter;
		const int Index;
		public:
		Interval(const Ray3D & ray, float inter, int index);
		public:
		VectorF3 ToPoint() const;
	};

	public:
	Interval Ray_Point(VectorF3 p);
};

#endif