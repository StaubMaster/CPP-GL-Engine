#ifndef  UNI_DEPTH_FACTORS_HPP
# define UNI_DEPTH_FACTORS_HPP

# include "Graphics/Uniform/Base/FloatNTypeBase.hpp"

struct DepthFactors;

namespace Uniform
{
typedef FloatNTypeBase<1, 1, 7, ::DepthFactors> DepthFactors;
};

#endif