#ifndef  UNI_MATRIX_4_4_HPP
# define UNI_MATRIX_4_4_HPP

# include "Graphics/Uniform/Base/FloatNTypeBase.hpp"

struct Matrix4x4;

namespace Uniform
{
typedef FloatNTypeBase<4, 4, 1, ::Matrix4x4> Matrix4x4;
};

#endif