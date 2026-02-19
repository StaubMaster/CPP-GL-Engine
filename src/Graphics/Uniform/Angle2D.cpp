#include "Graphics/Uniform/Angle2D.hpp"
#include "ValueType/Angle2D.hpp"



Uniform::Angle2D::Angle2D(::Shader::Base & shader, std::string name)
	: GBase(shader, name),
	Mat(shader, name)
{ }



void Uniform::Angle2D::Put(const ::Angle2D & obj)
{
	Mat.Put(obj.Mat);
}
