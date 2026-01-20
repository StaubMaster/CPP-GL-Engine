#ifndef  LIGHT_BASE_HPP
# define LIGHT_BASE_HPP

# include "ColorF4.hpp"

struct LightBase
{
	public:
	float	Intensity;
	ColorF4	Color;

	public:
	LightBase();
	LightBase(float intensity, ColorF4 color);
};

#endif