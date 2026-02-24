#ifndef  UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float3 : public Uniform::FloatN
{
	public:
	Float3(::Shader::Base & shader, std::string name);
	Float3(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;

	/*public:
	void Put(float val[3]);
	void Put(float val0, float val1, float val2);*/
};
};

#endif