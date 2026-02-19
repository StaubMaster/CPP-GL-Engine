#include "Graphics/Uniform/Base/Float1.hpp"
#include "OpenGL.hpp"



Uniform::Float1::Float1(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float1::Float1(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float1::PutData(const float * val)
{
	GL::Uniform1fv(Location, Count, val);
}
