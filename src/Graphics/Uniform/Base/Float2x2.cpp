#include "Graphics/Uniform/Base/Float2x2.hpp"
#include "OpenGL.hpp"



Uniform::Float2x2::Float2x2(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float2x2::Float2x2(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float2x2::PutData(const float * val)
{
	GL::UniformMatrix2fv(Location, Count, false, val);
}
