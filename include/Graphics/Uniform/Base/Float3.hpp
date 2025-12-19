
#ifndef  UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float3 : public Uniform::FloatN
{
	public:
		Float3(Uniform::NameShader name_shader);
		Float3(int count, Uniform::NameShader name_shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
