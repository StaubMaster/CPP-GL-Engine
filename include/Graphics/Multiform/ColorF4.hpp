#ifndef  MULTI_COLOR_F4_HPP
# define MULTI_COLOR_F4_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/ColorF4.hpp"
# include "ValueType/ColorF4.hpp"

namespace Multiform
{
class ColorF4 : public GBase<Uniform::ColorF4, ::ColorF4>
{
	public:
	ColorF4(std::string name);
};
};

#endif