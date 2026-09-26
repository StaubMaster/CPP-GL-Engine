#ifndef  LIGHT_SPOT_HPP
# define LIGHT_SPOT_HPP

# include "ValueType/Light/Base.hpp"
# include "ValueType/Vector/F3.hpp"
# include "ValueType/RangeF.hpp"

struct RayF3;
struct LineF3;

struct LightSpot
{
	LightBase	Base;
	VectorF3	Pos;
	VectorF3	Dir;
	RangeF		Range;

	~LightSpot() = default;
	LightSpot() = default;
	LightSpot(const LightSpot & other) = default;
	LightSpot & operator=(const LightSpot & other) = default;

	LightSpot(float intensity, ColorF4 color, VectorF3 pos, VectorF3 dir, RangeF range);
	LightSpot(LightBase base, VectorF3 pos, VectorF3 dir, RangeF range);

	LightSpot(LightBase base, RayF3 ray, RangeF range);
	LightSpot(LightBase base, LineF3 line, RangeF range);
};

#endif