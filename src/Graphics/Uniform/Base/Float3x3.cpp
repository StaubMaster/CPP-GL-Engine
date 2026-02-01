#include "Graphics/Uniform/Base/Float3x3.hpp"
#include "OpenGL.hpp"



Uniform::Float3x3::Float3x3(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float3x3::Float3x3(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float3x3::PutData(const float * val)
{
	GL::UniformMatrix3fv(Location, Count, false, val);
}
