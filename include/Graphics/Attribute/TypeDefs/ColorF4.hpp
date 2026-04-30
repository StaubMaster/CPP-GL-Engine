#ifndef  ATTRIB_COLOR_F4_HPP
# define ATTRIB_COLOR_F4_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<4, 1> ColorF4;
/*class ColorF4 : public Attribute::FloatN<4, 1>
{
	public:
	~ColorF4();
	ColorF4() = delete;
	ColorF4(Buffer::Array & buffer);

	ColorF4(const ColorF4 & other) = delete;
	ColorF4(Buffer::Array & buffer, const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);
};*/
};

#endif