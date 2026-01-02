
#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Point2D : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Point2D();
	Point2D(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexPos
	);
	~Point2D();

	Point2D(const Point2D & other);
	Point2D & operator=(const Point2D & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif
