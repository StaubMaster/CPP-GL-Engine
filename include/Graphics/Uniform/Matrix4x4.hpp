#ifndef  UNI_MATRIX_4_4_HPP
# define UNI_MATRIX_4_4_HPP

# include "Graphics/Uniform/Base/Float4x4.hpp"

struct Matrix4x4;

namespace Uniform
{
class Matrix4x4 : public Uniform::Float4x4
{
	public:
	Matrix4x4(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix4x4 & obj);
};
};

#endif