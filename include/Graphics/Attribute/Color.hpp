
#ifndef  ATTRIB_COLOR_HPP
# define ATTRIB_COLOR_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Color : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	Color();
	Color(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexCol
	);
	~Color();

	Color(const Color & other);
	Color & operator=(const Color & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif
