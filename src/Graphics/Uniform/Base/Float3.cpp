#include "Graphics/Uniform/Base/Float3.hpp"
#include "OpenGL/openGL.h"



Uniform::Float3::Float3(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float3::Float3(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float3::PutData(const float * val)
{
	glUniform3fv(Location, Count, val);
}
