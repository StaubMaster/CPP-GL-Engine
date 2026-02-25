#ifndef  UNI_FLOAT_3_3_HPP
# define UNI_FLOAT_3_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float3x3 : public Uniform::FloatN
{
	public:
	Float3x3(::Shader::Base & shader, std::string name);
	Float3x3(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;
};
};

#endif