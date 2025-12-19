#include "Graphics/Uniform/Base/UInt1.hpp"
#include "OpenGL/openGL.h"



Uniform::UInt1::UInt1(Uniform::NameShader name_shader) : UIntN(1, name_shader)
{ }
Uniform::UInt1::UInt1(int count, Uniform::NameShader name_shader) : UIntN(count, name_shader)
{ }



void Uniform::UInt1::PutData(const unsigned int * val)
{
	glUniform1uiv(Location, Count, val);
}
