#include "Graphics/Uniform/Point2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::Point2D::Point2D(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(name_shader)
{ }

void Uniform::Point2D::PutData(::Point2D p)
{
	Location.PutVoid(&p);
}
