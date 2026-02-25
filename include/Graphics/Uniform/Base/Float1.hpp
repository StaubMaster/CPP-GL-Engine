#ifndef  UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float1 : public Uniform::FloatN
{
	public:
	Float1(::Shader::Base & shader, std::string name);
	Float1(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;
};
};

#endif