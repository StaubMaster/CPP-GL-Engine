#ifndef  DEPTH_HPP
# define DEPTH_HPP

# include "DepthFactors.hpp"
# include "Range.hpp"
# include "ColorF4.hpp"

struct Depth
{
	public:
	DepthFactors	Factors;
	::Range			Range;
	ColorF4			Color;

	Depth();
	~Depth();

	Depth(const Depth & other);
	Depth & operator=(const Depth & other);

	Depth(DepthFactors factors, ::Range range, ColorF4 color);
};

#endif