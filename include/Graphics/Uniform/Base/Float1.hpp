#ifndef  UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float1 : public Uniform::FloatN
{
	public:
	Float1(Uniform::NameShader name_shader);
	Float1(Uniform::NameShader name_shader, int count);

	public:
	void PutData(const float * val) override;
};
};

#endif