#ifndef  ATTRIB_POINT_4D_HPP
# define ATTRIB_POINT_4D_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Point4D : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Point4D();
	Point4D(
		Buffer::Attribute & buffer,
		unsigned int indexPos
	);
	~Point4D();

	Point4D(const Point4D & other);
	Point4D & operator=(const Point4D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif