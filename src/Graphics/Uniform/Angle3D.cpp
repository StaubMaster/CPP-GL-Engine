#include "Graphics/Uniform/Angle3D.hpp"
#include "DataStruct/Angle3D.hpp"



Uniform::Angle3D::Angle3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Mat(name_shader)
{ }



void Uniform::Angle3D::Put(const ::Angle3D & obj)
{
	Mat.Put(obj.Mat);
}
