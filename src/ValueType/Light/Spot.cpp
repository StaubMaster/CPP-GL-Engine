#include "ValueType/Light/Spot.hpp"



LightSpot::LightSpot(float intensity, ColorF4 color, VectorF3 pos, VectorF3 dir, RangeF range)
	: Base(intensity, color)
	, Pos(pos)
	, Dir(dir)
	, Range(range)
{ }
LightSpot::LightSpot(LightBase base, VectorF3 pos, VectorF3 dir, RangeF range)
	: Base(base)
	, Pos(pos)
	, Dir(dir)
	, Range(range)
{ }
