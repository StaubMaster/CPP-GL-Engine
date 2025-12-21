#include "Graphics/Uniform/Base/Float3.hpp"

#include "OpenGL/openGL.h"
#include <iostream>


Uniform::Float3::Float3(Uniform::NameShader name_shader) : FloatN(1, name_shader)
{ }
Uniform::Float3::Float3(int count, Uniform::NameShader name_shader) : FloatN(count, name_shader)
{ }



void Uniform::Float3::PutData(const float * val)
{
	std::cout << "Uniform" << ' ' << "Float3" << '\n';
	glUniform3fv(Location, 1, val);
}
