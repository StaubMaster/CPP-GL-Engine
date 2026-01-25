#include "Graphics/Uniform/Base/Float1.hpp"
#include "OpenGL.hpp"



Uniform::Float1::Float1(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float1::Float1(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float1::PutData(const float * val)
{
	GL::Uniform1fv(Location, Count, val);
}
