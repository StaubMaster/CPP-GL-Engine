#ifndef  LIGHT_BASE_HPP
# define LIGHT_BASE_HPP

# include "ValueType/Color/F4.hpp"

struct LightBase
{
	float		Intensity = 0.0f;
	ColorF4		Color;

	~LightBase() = default;
	LightBase() = default;
	LightBase(const LightBase & other) = default;
	LightBase & operator=(const LightBase & other) = default;

	LightBase(float intensity, ColorF4 color);
};

#endif