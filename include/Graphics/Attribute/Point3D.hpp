#ifndef  ATTRIB_POINT_3D_HPP
# define ATTRIB_POINT_3D_HPP

# include "Graphics/Attribute/Base/Float3.hpp"

namespace Attribute
{
class Point3D : public Attribute::Float3
{
	public:
	~Point3D();
	Point3D();

	Point3D(const Point3D & other);
	Point3D & operator=(const Point3D & other);
};
};

#endif