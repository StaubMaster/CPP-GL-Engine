#ifndef  UNI_MATRIX_3_3_HPP
# define UNI_MATRIX_3_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix3x3;

namespace Uniform
{
typedef FloatN<3, 3, 1, ::Matrix3x3> Matrix3x3;
/*class Matrix3x3 : public Uniform::FloatN<3, 3, 1>
{
	public:
	Matrix3x3(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix3x3 & obj);
};*/
};

#endif