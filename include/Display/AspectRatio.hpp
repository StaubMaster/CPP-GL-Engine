#ifndef  DISPLAY_ASPECT_RATIO_HPP
# define DISPLAY_ASPECT_RATIO_HPP

# include "ValueType/Point2D.hpp"

/*
	AspectRatio.X = size.X / v
	AspectRatio.Y = size.Y / v

	AspectRatio.X [ 0.0 , 1.0 ]
	AspectRatio.Y [ 0.0 , 1.0 ]
*/
struct AspectRatio
{
	Point2D		Value;

	~AspectRatio();
	AspectRatio();
	
	AspectRatio(const AspectRatio & other);
	AspectRatio & operator=(const AspectRatio & other);

	AspectRatio(Point2D size);
	void Change(Point2D size);
};

#endif