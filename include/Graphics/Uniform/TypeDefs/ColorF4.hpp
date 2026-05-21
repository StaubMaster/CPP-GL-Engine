#ifndef  UNI_COLOR_F4_HPP
# define UNI_COLOR_F4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct ColorF4;

namespace Uniform
{
typedef FloatN<4, 1, 1, ::ColorF4> ColorF4;

template <unsigned int Count>
using ColorF4Array = FloatN<4, 1, Count, ::ColorF4>;
};

#endif