#include "Graphics/Uniform/Base/Float2.hpp"
#include "OpenGL/openGL.h"



Uniform::Float2::Float2(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float2::Float2(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float2::PutData(const float * val)
{
	glUniform2fv(Location, Count, val);
}
