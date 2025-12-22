#include "Graphics/Uniform/Point3D.hpp"
#include "DataStruct/Point3D.hpp"



Uniform::Point3D::Point3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(name_shader)
{ }



void Uniform::Point3D::PutData(::Point3D p)
{
	Location.PutVoid(&p);
}
