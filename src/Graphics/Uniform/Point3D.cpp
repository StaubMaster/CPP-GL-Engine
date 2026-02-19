#include "Graphics/Uniform/Point3D.hpp"
#include "ValueType/Point3D.hpp"



Uniform::Point3D::Point3D(::Shader::Base & shader, std::string name)
	: Float3(shader, name)
{ }

void Uniform::Point3D::Put(const ::Point3D & obj)
{
	PutVoid(&obj);
}
