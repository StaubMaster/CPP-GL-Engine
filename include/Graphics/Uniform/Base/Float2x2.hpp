#ifndef  UNI_FLOAT_2_2_HPP
# define UNI_FLOAT_2_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float2x2 : public Uniform::FloatN
{
	public:
	Float2x2(Uniform::NameShader name_shader);
	Float2x2(Uniform::NameShader name_shader, int count);

	public:
	void PutData(const float * val) override;
};
};

#endif