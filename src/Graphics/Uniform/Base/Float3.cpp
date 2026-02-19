#include "Graphics/Uniform/Base/Float3.hpp"
#include "OpenGL.hpp"



Uniform::Float3::Float3(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float3::Float3(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float3::PutData(const float * val)
{
	GL::Uniform3fv(Location, Count, val);
}
