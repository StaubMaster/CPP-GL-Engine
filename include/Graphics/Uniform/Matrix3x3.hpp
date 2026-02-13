#ifndef  UNI_MATRIX_3_3_HPP
# define UNI_MATRIX_3_3_HPP

# include "Graphics/Uniform/Base/Float3x3.hpp"

struct Matrix3x3;

namespace Uniform
{
class Matrix3x3 : public Uniform::Float3x3
{
	public:
	Matrix3x3(Uniform::NameShader name_shader);

	public:
	void Put(const ::Matrix3x3 & obj);
};
};

#endif