#ifndef  UNI_COLOR_F4_HPP
# define UNI_COLOR_F4_HPP

# include "Graphics/Uniform/Base/FloatNTypeBase.hpp"

struct ColorF4;

namespace Uniform
{
typedef FloatNTypeBase<4, 1, 1, ::ColorF4> ColorF4;

template <unsigned int Count>
using ColorF4Array = FloatNTypeBase<4, 1, Count, ::ColorF4>;
};

#endif