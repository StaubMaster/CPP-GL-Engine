#ifndef  ATTRIB_COLOR_F4_HPP
# define ATTRIB_COLOR_F4_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class ColorF4 : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	ColorF4();
	ColorF4(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexCol
	);
	~ColorF4();

	ColorF4(const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif