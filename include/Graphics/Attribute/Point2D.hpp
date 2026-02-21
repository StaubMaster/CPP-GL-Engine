#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "Graphics/Attribute/Base/Float2.hpp"

namespace Attribute
{
class Point2D : public Attribute::Float2
{
	public:
	~Point2D();
	Point2D();

	Point2D(const Point2D & other);
	Point2D & operator=(const Point2D & other);
};
};

#endif