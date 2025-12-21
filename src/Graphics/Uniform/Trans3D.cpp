#include "Graphics/Uniform/Trans3D.hpp"
#include "DataStruct/Trans3D.hpp"
#include "OpenGL/openGL.h"
#include <iostream>



Uniform::Trans3D::Trans3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Pos(name_shader.Suffix(".Pos")),
	Rot(name_shader.Suffix(".Rot"))
{ }

void Uniform::Trans3D::PutData(::Trans3D t)
{
	std::cout << "Uniform" << ' ' << "Trans3D" << '\n';
	Pos.PutData(t.Pos);
	Rot.PutData(t.Rot);
}
