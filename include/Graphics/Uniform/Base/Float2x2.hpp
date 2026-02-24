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
	Float2x2(::Shader::Base & shader, std::string name);
	Float2x2(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;

	/*public:
	void Put(float val[4]);
	void Put(
		float val00, float val01,
		float val10, float val11
	);*/
};
};

#endif