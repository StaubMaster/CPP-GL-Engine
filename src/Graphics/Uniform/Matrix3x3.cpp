#include "Graphics/Uniform/Matrix3x3.hpp"
#include "ValueType/Matrix3x3.hpp"



Uniform::Matrix3x3::Matrix3x3(::Shader::Base & shader, std::string name)
	: Float3x3(shader, name)
{ }

void Uniform::Matrix3x3::Put(const ::Matrix3x3 & obj)
{
	PutVoid(&obj);
}
