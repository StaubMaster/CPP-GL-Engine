#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct VectorF2;
struct VectorF2; typedef VectorF2 VectorF2;

namespace Uniform
{
typedef FloatN<2, 1, 1, ::VectorF2> VectorF2;

template <unsigned int Count>
using VectorF2Array = FloatN<2, 1, Count, ::VectorF2>;
};

#endif