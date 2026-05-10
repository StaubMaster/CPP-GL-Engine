#include "ValueType/LightSolar.hpp"



LightSolar::LightSolar()
{ }
LightSolar::LightSolar(float intensity, ColorF4 color, VectorF3 dir) :
	Base(intensity, color),
	Dir(dir)
{ }
