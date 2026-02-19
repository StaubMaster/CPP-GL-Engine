#ifndef  ATTRIB_POINT_3D_HPP
# define ATTRIB_POINT_3D_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Point3D : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Point3D();
	Point3D(
		Buffer::Attribute & buffer,
		unsigned int indexPos
	);
	~Point3D();

	Point3D(const Point3D & other);
	Point3D & operator=(const Point3D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif