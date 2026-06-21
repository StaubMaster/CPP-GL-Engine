#ifndef  UNI_MATRIX_3_3_HPP
# define UNI_MATRIX_3_3_HPP

# include "Graphics/Uniform/General/FloatNTypeBase.hpp"

struct Matrix3x3;

namespace Uniform
{
typedef FloatNTypeBase<3, 3, 1, ::Matrix3x3> Matrix3x3;
};

#endif