#ifndef  UNI_MATRIX_4_4_HPP
# define UNI_MATRIX_4_4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix4x4;

namespace Uniform
{
typedef FloatN<4, 4, 1, ::Matrix4x4> Matrix4x4;
/*class Matrix4x4 : public Uniform::FloatN<4, 4, 1>
{
	public:
	Matrix4x4(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix4x4 & obj);
};*/
};

#endif