#include "Graphics/Uniform/Matrix2x2.hpp"
#include "ValueType/Matrix2x2.hpp"



Uniform::Matrix2x2::Matrix2x2(::Shader::Base & shader, std::string name)
	: Float2x2(shader, name)
{ }

void Uniform::Matrix2x2::Put(const ::Matrix2x2 & obj)
{
	PutVoid(&obj);
}
