#ifndef  UNI_FLOAT_4_HPP
# define UNI_FLOAT_4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float4 : public Uniform::FloatN
{
	public:
	Float4(Uniform::NameShader name_shader);
	Float4(Uniform::NameShader name_shader, int count);

	public:
	void PutData(const float * val) override;
};
};

#endif