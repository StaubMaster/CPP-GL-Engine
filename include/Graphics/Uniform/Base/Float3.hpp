#ifndef  UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float3 : public Uniform::FloatN
{
	public:
	Float3(::Shader::Base & shader, std::string name);
	Float3(::Shader::Base & shader, std::string name, int count);

	public:
	void PutData(const float * val) override;
};
};

#endif