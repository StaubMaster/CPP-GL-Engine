#include "Graphics/Uniform/Matrix3x3.hpp"
#include "ValueType/Matrix3x3.hpp"



Uniform::Matrix3x3::Matrix3x3(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 3, 3, 1)
{ }

void Uniform::Matrix3x3::Put(const ::Matrix3x3 & obj)
{
	PutVoid(&obj);
}
