#include "ValueType/LightSpot.hpp"



LightSpot::LightSpot()
{ }
LightSpot::LightSpot(float intensity, ColorF4 color, Point3D pos, Point3D dir, ::Range range) :
	Base(intensity, color),
	Pos(pos),
	Dir(dir),
	Range(range)
{ }
