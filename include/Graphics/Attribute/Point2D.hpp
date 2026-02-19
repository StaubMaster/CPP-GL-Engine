#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Point2D : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Point2D();
	Point2D(
		Buffer::Attribute & buffer,
		unsigned int indexPos
	);
	~Point2D();

	Point2D(const Point2D & other);
	Point2D & operator=(const Point2D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif