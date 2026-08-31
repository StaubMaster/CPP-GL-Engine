#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/General/FloatNTypeBase.hpp"

struct VectorF2;

namespace Uniform
{
typedef FloatNTypeBase<2, 1, 1, ::VectorF2> VectorF2;

template <unsigned int Count>
using VectorF2Array = FloatNTypeBase<2, 1, Count, ::VectorF2>;
};

#endif