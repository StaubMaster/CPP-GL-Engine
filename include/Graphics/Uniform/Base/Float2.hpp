#ifndef  UNI_FLOAT_2_HPP
# define UNI_FLOAT_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float2 : public Uniform::FloatN
{
	public:
	Float2(Uniform::NameShader name_shader);
	Float2(Uniform::NameShader name_shader, int count);

	public:
	void PutData(const float * val) override;
};
};

#endif