#include "Graphics/Uniform/Point3D.hpp"
#include "DataStruct/Point3D.hpp"



Uniform::Point3D::Point3D(Uniform::NameShader name_shader) : Float3(name_shader)
{ }

void Uniform::Point3D::Put(const ::Point3D & p)
{
	PutVoid(&p);
}
