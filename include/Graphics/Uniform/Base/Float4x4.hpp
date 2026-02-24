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

	/*public:
	void Put(float val[16]);
	void Put(
		float val00, float val01, float val02, float val03
		float val10, float val11, float val12, float val13
		float val20, float val21, float val22, float val23,
		float val30, float val31, float val32, float val33
	);*/
};
};

#endif