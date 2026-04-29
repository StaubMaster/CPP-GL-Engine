#include "Graphics/Uniform/Matrix4x4.hpp"
#include "ValueType/Matrix4x4.hpp"



Uniform::Matrix4x4::Matrix4x4(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 4, 4, 1)
{ }

void Uniform::Matrix4x4::Put(const ::Matrix4x4 & obj)
{
	PutVoid(&obj);
}
