#include "Graphics/Uniform/Base/Float2x2.hpp"
#include "OpenGL.hpp"



Uniform::Float2x2::Float2x2(Uniform::NameShader name_shader) : FloatN(name_shader, 1)
{ }
Uniform::Float2x2::Float2x2(Uniform::NameShader name_shader, int count) : FloatN(name_shader, count)
{ }



void Uniform::Float2x2::PutData(const float * val)
{
	GL::UniformMatrix2fv(Location, Count, false, val);
}
