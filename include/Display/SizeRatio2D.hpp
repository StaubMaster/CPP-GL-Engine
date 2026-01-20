#ifndef  DISPLAY_SIZERATIO2D_HPP
# define DISPLAY_SIZERATIO2D_HPP

# include "ValueType/Point2D.hpp"

struct SizeRatio2D
{
	Point2D	Size;
	Point2D	Ratio;

	static Point2D NormalRatio(const Point2D & Size);

	SizeRatio2D();
	SizeRatio2D(const SizeRatio2D & other);
	SizeRatio2D(const Point2D & size);

	SizeRatio2D & operator=(const SizeRatio2D & other);
	SizeRatio2D & operator=(const Point2D & size);
};

#endif