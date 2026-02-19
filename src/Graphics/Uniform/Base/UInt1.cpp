#include "Graphics/Uniform/Base/UInt1.hpp"
#include "OpenGL.hpp"



Uniform::UInt1::UInt1(::Shader::Base & shader, std::string name)
	: UIntN(shader, name, 1)
{ }
Uniform::UInt1::UInt1(::Shader::Base & shader, std::string name, int count)
	: UIntN(shader, name, count)
{ }



void Uniform::UInt1::PutData(const unsigned int * val)
{
	GL::Uniform1uiv(Location, Count, val);
}
