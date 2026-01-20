#ifndef  UNI_DEPTH_FACTORS_HPP
# define UNI_DEPTH_FACTORS_HPP

# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDeclare.hpp"

namespace Uniform
{
class DepthFactors : public Uniform::Float1
{
	public:
	DepthFactors(Uniform::NameShader name_shader);

	public:
	void Put(const ::DepthFactors & obj);
};
};

#endif