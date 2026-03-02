#ifndef  DISPLAY_DISPLAY_POSITION_HPP
# define DISPLAY_DISPLAY_POSITION_HPP

# include "PixelPosition.hpp"
# include "ValueType/Point2D.hpp"

// allways from Bottom Right
struct DisplayPosition
{
	PixelPosition Window;
	PixelPosition Buffer;
	Point2D NormalAbs; // [ 0 ; 1 ]
	Point2D NormalRel; // [ -1 ; +1 ]
};

#endif