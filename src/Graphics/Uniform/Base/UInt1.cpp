#include "Graphics/Uniform/Base/UInt1.hpp"
#include "OpenGL/openGL.h"



Uniform::UInt1::UInt1(Uniform::NameShader name_shader) : UIntN(name_shader, 1)
{ }
Uniform::UInt1::UInt1(Uniform::NameShader name_shader, int count) : UIntN(name_shader, count)
{ }



void Uniform::UInt1::PutData(const unsigned int * val)
{
	glUniform1uiv(Location, Count, val);
}
