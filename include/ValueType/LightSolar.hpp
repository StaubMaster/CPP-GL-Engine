#ifndef  LIGHT_SOLAR_HPP
# define LIGHT_SOLAR_HPP

# include "LightBase.hpp"
# include "ValueType/Vector/F3.hpp"

struct LightSolar
{
	public:
	LightBase	Base;
	VectorF3		Dir;

	public:
	LightSolar();
	LightSolar(float intensity, ColorF4 color, VectorF3 dir);
};

#endif