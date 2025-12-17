#ifndef  DISPLAY_PIXELCOORD2D_HPP
# define DISPLAY_PIXELCOORD2D_HPP

# include "DataStruct/Point2D.hpp"

struct PixelCoord2D : public Point2D
{
	PixelCoord2D();
	PixelCoord2D(Point2D p);
};

#endif