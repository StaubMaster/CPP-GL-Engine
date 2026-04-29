#include "Graphics/Uniform/Float.hpp"



Uniform::Float::Float(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1, 1, 1)
{ }

void Uniform::Float::Put(const float & val)
{
	PutVoid(&val);
}
