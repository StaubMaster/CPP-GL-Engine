
#ifndef  ATTRIB_POINT_4D_HPP
# define ATTRIB_POINT_4D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Point4D : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Point4D();
	Point4D(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexPos
	);
	~Point4D();

	Point4D(const Point4D & other);
	Point4D & operator=(const Point4D & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif
