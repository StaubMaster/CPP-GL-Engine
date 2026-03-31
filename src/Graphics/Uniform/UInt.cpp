#include "Graphics/Uniform/UInt.hpp"



Uniform::UInt::UInt(::Shader::Base & shader, std::string name)
	: UInt1(shader, name)
{ }

void Uniform::UInt::Put(const unsigned int & val)
{
	PutVoid(&val);
}
