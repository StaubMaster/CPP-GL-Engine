#ifndef  LIGHT_SPOT_HPP
# define LIGHT_SPOT_HPP

# include "LightBase.hpp"
# include "ValueType/Vector/F3.hpp"
# include "Range.hpp"

struct LightSpot
{
	public:
	LightBase	Base;
	VectorF3		Pos;
	VectorF3		Dir;
	::Range		Range;

	public:
	LightSpot();
	LightSpot(float intensity, ColorF4 color, VectorF3 pos, VectorF3 dir, ::Range range);
};

#endif