#ifndef  LIGHT_POINT_HPP
# define LIGHT_POINT_HPP

# include "ValueType/Light/Base.hpp"
# include "ValueType/Vector/F3.hpp"

struct LightPoint
{
	LightBase	Base;
	VectorF3	Pos;

	~LightPoint() = default;
	LightPoint() = default;
	LightPoint(const LightPoint & other) = default;
	LightPoint & operator=(const LightPoint & other) = default;

	LightPoint(float intensity, ColorF4 color, VectorF3 pos);
	LightPoint(LightBase base, VectorF3 pos);
};

#endif