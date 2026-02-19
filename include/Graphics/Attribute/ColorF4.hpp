#ifndef  ATTRIB_COLOR_F4_HPP
# define ATTRIB_COLOR_F4_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class ColorF4 : public Attribute::Base
{
	private:
	Attribute::FloatN Location;

	public:
	ColorF4();
	ColorF4(
		Buffer::Attribute & buffer,
		GL::AttributeID indexCol
	);
	~ColorF4();

	ColorF4(const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif