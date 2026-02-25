#ifndef  UNI_FLOAT_HPP
# define UNI_FLOAT_HPP

# include "Graphics/Uniform/Base/Float1.hpp"

namespace Uniform
{
class Float : public Uniform::Float1
{
	public:
	Float(::Shader::Base & shader, std::string name);

	public:
	void Put(const float & val);
};
};

#endif