#ifndef  UNI_MATRIX_2_2_HPP
# define UNI_MATRIX_2_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix2x2;

namespace Uniform
{
class Matrix2x2 : public Uniform::FloatN
{
	public:
	Matrix2x2(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix2x2 & obj);
};
};

#endif