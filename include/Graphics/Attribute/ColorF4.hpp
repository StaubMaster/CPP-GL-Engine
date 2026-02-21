#ifndef  ATTRIB_COLOR_F4_HPP
# define ATTRIB_COLOR_F4_HPP

# include "Graphics/Attribute/Base/Float4.hpp"

namespace Attribute
{
class ColorF4 : public Attribute::Float4
{
	public:
	~ColorF4();
	ColorF4();

	ColorF4(const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);
};
};

#endif