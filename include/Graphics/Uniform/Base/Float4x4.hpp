#ifndef  UNI_FLOAT_4_4_HPP
# define UNI_FLOAT_4_4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float4x4 : public Uniform::FloatN
{
	public:
	Float4x4(::Shader::Base & shader, std::string name);
	Float4x4(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;
};
};

#endif