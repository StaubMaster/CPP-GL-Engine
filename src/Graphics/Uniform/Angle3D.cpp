#include "Graphics/Uniform/Angle3D.hpp"
#include "Graphics/Shader/Base.hpp"
#include "DataStruct/Angle3D.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



Uniform::Angle3D::Angle3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(Find())
{ }

void Uniform::Angle3D::PutData(::Angle3D a)
{
	std::cout << "Uniform" << ' ' << "Angle3D" << '\n';
	glUniformMatrix3fv(Location, 1, true, (const float *)(&a.Mat));
}
