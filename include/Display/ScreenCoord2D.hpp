#ifndef  DISPLAY_SCREENCOORD2D_HPP
# define DISPLAY_SCREENCOORD2D_HPP

# include "ValueType/Point2D.hpp"

struct ScreenCoord2D : public Point2D
{
	ScreenCoord2D();
	ScreenCoord2D(Point2D p);
};

#endif