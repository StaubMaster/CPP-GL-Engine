#ifndef  ATTRIB_POINT_4D_HPP
# define ATTRIB_POINT_4D_HPP

# include "Graphics/Attribute/Base/Float4.hpp"

namespace Attribute
{
class Point4D : public Attribute::Float4
{
	public:
	~Point4D();
	Point4D();

	Point4D(const Point4D & other);
	Point4D & operator=(const Point4D & other);
};
};

#endif