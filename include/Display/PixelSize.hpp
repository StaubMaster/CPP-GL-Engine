#ifndef  DISPLAY_PIXEL_SIZE_HPP
# define DISPLAY_PIXEL_SIZE_HPP

# include "ValueType/Point2D.hpp"

struct PixelSize
{
	Point2D	Full;
	Point2D	Half;

	~PixelSize();
	PixelSize();

	PixelSize(const PixelSize & other);
	PixelSize & operator=(const PixelSize & other);

	void ChangeFull(Point2D size);

	static PixelSize FromFull(Point2D size);
};

#endif