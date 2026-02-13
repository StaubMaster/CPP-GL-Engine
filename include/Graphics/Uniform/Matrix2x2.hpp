#ifndef  UNI_MATRIX_2_2_HPP
# define UNI_MATRIX_2_2_HPP

# include "Graphics/Uniform/Base/Float2x2.hpp"

struct Matrix2x2;

namespace Uniform
{
class Matrix2x2 : public Uniform::Float2x2
{
	public:
	Matrix2x2(Uniform::NameShader name_shader);

	public:
	void Put(const ::Matrix2x2 & obj);
};
};

#endif