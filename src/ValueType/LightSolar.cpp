#include "ValueType/LightSolar.hpp"



LightSolar::LightSolar()
{ }
LightSolar::LightSolar(float intensity, ColorF4 color, Point3D dir) :
	Base(intensity, color),
	Dir(dir)
{ }
