#ifndef  DEPTH_HPP
# define DEPTH_HPP

# include "ValueType/DepthFactors.hpp"
# include "ValueType/RangeF.hpp"
# include "ValueType/Color/F4.hpp"

struct Depth
{
	public:
	DepthFactors	Factors;
	RangeF			Range;
	ColorF4			Color;

	Depth();
	~Depth();

	Depth(const Depth & other);
	Depth & operator=(const Depth & other);

	Depth(DepthFactors factors, RangeF range, ColorF4 color);
};

#endif