#ifndef  MULTIFORM_DEPTH_FACTORS_3D_HPP
# define MULTIFORM_DEPTH_FACTORS_3D_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/DepthFactors.hpp"
# include "ValueType/DepthFactors.hpp"

namespace Multiform
{
typedef GBase<Uniform::DepthFactors, ::DepthFactors> DepthFactors;
/*class DepthFactors : public GBase<Uniform::DepthFactors, ::DepthFactors>
{
	public:
		DepthFactors(std::string name);
};*/
};

#endif