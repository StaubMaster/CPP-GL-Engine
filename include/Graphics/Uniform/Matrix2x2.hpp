#ifndef  UNI_MATRIX_2_2_HPP
# define UNI_MATRIX_2_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix2x2;

namespace Uniform
{
typedef FloatN<2, 2, 1, ::Matrix2x2> Matrix2x2;
/*class Matrix2x2 : public Uniform::FloatN<2, 2, 1>
{
	public:
	Matrix2x2(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix2x2 & obj);
};*/
};

#endif