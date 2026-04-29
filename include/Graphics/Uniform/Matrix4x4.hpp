#ifndef  UNI_MATRIX_4_4_HPP
# define UNI_MATRIX_4_4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Matrix4x4;

namespace Uniform
{
class Matrix4x4 : public Uniform::FloatN
{
	public:
	Matrix4x4(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Matrix4x4 & obj);
};
};

#endif