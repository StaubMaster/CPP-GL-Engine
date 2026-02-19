#include "Graphics/Uniform/Base/Float3x3.hpp"
#include "OpenGL.hpp"



Uniform::Float3x3::Float3x3(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float3x3::Float3x3(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float3x3::PutData(const float * val)
{
	GL::UniformMatrix3fv(Location, Count, false, val);
}
