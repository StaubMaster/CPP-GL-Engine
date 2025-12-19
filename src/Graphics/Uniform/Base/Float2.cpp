#include "Graphics/Uniform/Base/Float2.hpp"
#include "OpenGL/openGL.h"



Uniform::Float2::Float2(Uniform::NameShader name_shader) : FloatN(1, name_shader)
{ }
Uniform::Float2::Float2(int count, Uniform::NameShader name_shader) : FloatN(count, name_shader)
{ }



void Uniform::Float2::PutData(const float * val)
{
	glUniform2fv(Location, Count, val);
}
