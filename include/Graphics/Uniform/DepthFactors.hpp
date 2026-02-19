#ifndef  UNI_DEPTH_FACTORS_HPP
# define UNI_DEPTH_FACTORS_HPP

# include "Graphics/Uniform/Base/Float1.hpp"

struct DepthFactors;

namespace Uniform
{
class DepthFactors : public Uniform::Float1
{
	public:
	DepthFactors(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::DepthFactors & obj);
};
};

#endif