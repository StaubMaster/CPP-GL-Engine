#ifndef  DEPTH_HPP
# define DEPTH_HPP

# include "ValueType/DepthFactors.hpp"
# include "ValueType/RangeF.hpp"
# include "ValueType/Color/F4.hpp"

struct Depth
{
	DepthFactors	Factors;
	RangeF			Range;
	ColorF4			Color;

	~Depth() = default;
	Depth() = default;
	Depth(const Depth & other) = default;
	Depth & operator=(const Depth & other) = default;

	Depth(const DepthFactors & factors, const RangeF & range, const ColorF4 & color);
};

#endif