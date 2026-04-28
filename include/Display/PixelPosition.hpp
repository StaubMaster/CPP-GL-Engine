#ifndef  DISPLAY_PIXEL_POSITION_HPP
# define DISPLAY_PIXEL_POSITION_HPP

# include "ValueType/Point2D.hpp"

struct PixelPosition
{
	Point2D		Corner;
	Point2D		Center;

	~PixelPosition();
	PixelPosition();

	PixelPosition(const PixelPosition & other);
	PixelPosition & operator=(const PixelPosition & other);
};

#endif