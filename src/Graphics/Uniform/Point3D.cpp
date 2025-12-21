#include "Graphics/Uniform/Point3D.hpp"
#include "DataStruct/Point3D.hpp"

#include <iostream>



Uniform::Point3D::Point3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(name_shader)
{ }



void Uniform::Point3D::PutData(::Point3D p)
{
	std::cout << "Uniform" << ' ' << "Point3D" << '\n';
	Location.PutVoid(&p);
}
