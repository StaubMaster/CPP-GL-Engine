#include "Graphics/Uniform/Base/Float1.hpp"
#include "OpenGL/openGL.h"



Uniform::Float1::Float1(Uniform::NameShader name_shader) : FloatN(1, name_shader)
{ }
Uniform::Float1::Float1(int count, Uniform::NameShader name_shader) : FloatN(count, name_shader)
{ }



void Uniform::Float1::PutData(const float * val)
{
	glUniform1fv(Location, Count, val);
}
