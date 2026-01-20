#include "Graphics/Uniform/Base/Float4.hpp"
#include "OpenGL/openGL.h"



Uniform::Float4::Float4(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float4::Float4(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float4::PutData(const float * val)
{
	glUniform4fv(Location, Count, val);
}
