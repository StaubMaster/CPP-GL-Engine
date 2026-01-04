#include "Graphics/Uniform/Base/Float3x3.hpp"
#include "OpenGL/openGL.h"



Uniform::Float3x3::Float3x3(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float3x3::Float3x3(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float3x3::PutData(const float * val)
{
	glUniformMatrix3fv(Location, Count, true, val);
}
