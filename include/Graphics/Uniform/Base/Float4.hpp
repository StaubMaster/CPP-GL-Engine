#ifndef  UNI_FLOAT_4_HPP
# define UNI_FLOAT_4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float4 : public Uniform::FloatN
{
	public:
	Float4(::Shader::Base & shader, std::string name);
	Float4(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;

	/*public:
	void Put(float val[4]);
	void Put(float val0, float val1, float val2, float val3);*/
};
};

#endif