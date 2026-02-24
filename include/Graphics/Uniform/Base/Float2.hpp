#ifndef  UNI_FLOAT_2_HPP
# define UNI_FLOAT_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class Float2 : public Uniform::FloatN
{
	public:
	Float2(::Shader::Base & shader, std::string name);
	Float2(::Shader::Base & shader, std::string name, int count);

	protected:
	void PutData(const float * val) override;

	/*public:
	void Put(float val[2]);
	void Put(float val0, float val1);*/

};
};

#endif