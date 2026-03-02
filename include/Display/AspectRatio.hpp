#ifndef  DISPLAY_ASPECTRATIO_HPP
# define DISPLAY_ASPECTRATIO_HPP

# include "ValueType/Point2D.hpp"

/*
	AspectRatio.X = size.X / v
	AspectRatio.Y = size.Y / v

	AspectRatio.X [ 0.0 , 1.0 ]
	AspectRatio.Y [ 0.0 , 1.0 ]
*/
struct AspectRatio : public Point2D
{
	public:
//	~AspectRatio();
//	AspectRatio();

	AspectRatio();
	AspectRatio(Point2D size);

	void Change(Point2D size);
};

#endif