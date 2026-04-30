#ifndef  UNI_FLOAT_HPP
# define UNI_FLOAT_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Uniform
{
typedef FloatN<1, 1, 1, float> Float;
/*class Float : public Uniform::FloatN<1, 1, 1>
{
	public:
	Float(::Shader::Base & shader, std::string name);

	public:
	void Put(const float & val);
};*/
};

#endif