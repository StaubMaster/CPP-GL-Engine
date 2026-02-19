#include "Graphics/Uniform/Base/Float2.hpp"
#include "OpenGL.hpp"



Uniform::Float2::Float2(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float2::Float2(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float2::PutData(const float * val)
{
	GL::Uniform2fv(Location, Count, val);
}
