#include "Graphics/Uniform/Matrix3x3.hpp"
#include "ValueType/Matrix3x3.hpp"



Uniform::Matrix3x3::Matrix3x3(Uniform::NameShader name_shader) : Float3x3(name_shader)
{ }

void Uniform::Matrix3x3::Put(const ::Matrix3x3 & p)
{
	PutVoid(&p);
}
