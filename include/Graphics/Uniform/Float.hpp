#ifndef  UNI_FLOAT_HPP
# define UNI_FLOAT_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Uniform
{
class Float : public Uniform::FloatN
{
	public:
	Float(::Shader::Base & shader, std::string name);

	public:
	void Put(const float & val);
};
};

#endif