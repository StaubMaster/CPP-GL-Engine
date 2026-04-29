#ifndef  UNI_MATRIX_3_3_HPP
# define UNI_MATRIX_3_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix3x3;

namespace Uniform
{
class Matrix3x3 : public Uniform::FloatN
{
	public:
	Matrix3x3(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix3x3 & obj);
};
};

#endif