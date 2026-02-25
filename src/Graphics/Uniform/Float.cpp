#include "Graphics/Uniform/Float.hpp"



Uniform::Float::Float(::Shader::Base & shader, std::string name)
	: Float1(shader, name)
{ }

void Uniform::Float::Put(const float & val)
{
	PutVoid(&val);
}
