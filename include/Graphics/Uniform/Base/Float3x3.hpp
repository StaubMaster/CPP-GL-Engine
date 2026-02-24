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

	/*public:
	void Put(float val[9]);
	void Put(
		float val00, float val01, float val02,
		float val10, float val11, float val12,
		float val20, float val21, float val22
	);*/
};
};

#endif