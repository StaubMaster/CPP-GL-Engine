#ifndef  ATTRIB_COLOR_F4_HPP
# define ATTRIB_COLOR_F4_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class ColorF4 : public Attribute::FloatN
{
	public:
	~ColorF4();
	ColorF4() = delete;
	ColorF4(Buffer::Array & buffer);

	ColorF4(const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);
};
};

#endif