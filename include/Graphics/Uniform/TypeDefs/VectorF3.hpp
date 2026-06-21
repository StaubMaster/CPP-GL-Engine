#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/General/FloatNTypeBase.hpp"

struct VectorF3;

namespace Uniform
{
typedef FloatNTypeBase<3, 1, 1, ::VectorF3> VectorF3;
};

#endif