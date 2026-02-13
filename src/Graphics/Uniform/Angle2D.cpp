#include "Graphics/Uniform/Angle2D.hpp"
#include "ValueType/Angle2D.hpp"



Uniform::Angle2D::Angle2D(Uniform::NameShader name_shader) : GBase(name_shader),
	Mat(name_shader)
{ }



void Uniform::Angle2D::Put(const ::Angle2D & obj)
{
	Mat.Put(obj.Mat);
}
