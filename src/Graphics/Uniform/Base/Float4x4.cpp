#include "Graphics/Uniform/Base/Float4x4.hpp"
#include "OpenGL.hpp"



Uniform::Float4x4::Float4x4(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1)
{ }
Uniform::Float4x4::Float4x4(::Shader::Base & shader, std::string name, int count)
	: FloatN(shader, name, count)
{ }



void Uniform::Float4x4::PutData(const float * val)
{
	GL::UniformMatrix4fv(Location, Count, false, val);
}
