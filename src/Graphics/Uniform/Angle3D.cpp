#include "Graphics/Uniform/Angle3D.hpp"
#include "ValueType/Angle3D.hpp"



Uniform::Angle3D::Angle3D(::Shader::Base & shader, std::string name)
	: GBase(shader, name),
	Mat(shader, name)
{ }



void Uniform::Angle3D::Put(const ::Angle3D & obj)
{
	Mat.Put(obj.Mat);
}
