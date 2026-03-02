#ifndef  USER_PARAMETER_MOUSE_POSITION_HPP
# define USER_PARAMETER_MOUSE_POSITION_HPP

# include "ValueType/Point2D.hpp"

namespace UserParameter
{

namespace Mouse
{

struct PixelPosition
{
	Point2D Corner;
	Point2D Center;
};

struct CornerPosition
{
	Point2D Normal0;
	Point2D Normal1;
	PixelPosition Window;
	PixelPosition Buffer;
};

struct Position
{
	CornerPosition TopLeft;
	CornerPosition BottomLeft;
};

};

};

#endif