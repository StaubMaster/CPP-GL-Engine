#include "Graphics/Uniform/Base/Float4.hpp"
#include "OpenGL.hpp"



Uniform::Float4::Float4(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float4::Float4(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float4::PutData(const float * val)
{
	GL::Uniform4fv(Location, Count, val);
}
