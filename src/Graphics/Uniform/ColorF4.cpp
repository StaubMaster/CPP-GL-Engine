#include "Graphics/Uniform/ColorF4.hpp"
#include "ValueType/ColorF4.hpp"



Uniform::ColorF4::ColorF4(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 4, 1, 1)
{ }

void Uniform::ColorF4::Put(const ::ColorF4 & obj)
{
	PutVoid(&obj);
}
