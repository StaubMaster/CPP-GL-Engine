#include "Graphics/Uniform/Angle3D.hpp"
#include "Graphics/Shader/Base.hpp"
#include "DataStruct/Angle3D.hpp"
#include "OpenGL/openGL.h"



Uniform::Angle3D::Angle3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(Locate())
{ }



void Uniform::Angle3D::ReLocate()
{
	Location = Locate();
}
void Uniform::Angle3D::PutData(::Angle3D a)
{
	glUniformMatrix3fv(Location, 1, true, (const float *)(&a.Mat));
}
