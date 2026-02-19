#include "Graphics/Uniform/ColorF4.hpp"
#include "ValueType/ColorF4.hpp"



Uniform::ColorF4::ColorF4(::Shader::Base & shader, std::string name)
	: Float4(shader, name)
{ }

void Uniform::ColorF4::Put(const ::ColorF4 & obj)
{
	PutVoid(&obj);
}
