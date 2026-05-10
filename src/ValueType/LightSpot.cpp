#include "ValueType/LightSpot.hpp"



LightSpot::LightSpot()
{ }
LightSpot::LightSpot(float intensity, ColorF4 color, VectorF3 pos, VectorF3 dir, ::Range range) :
	Base(intensity, color),
	Pos(pos),
	Dir(dir),
	Range(range)
{ }
