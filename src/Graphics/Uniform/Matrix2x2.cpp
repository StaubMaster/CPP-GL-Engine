#include "Graphics/Uniform/Matrix2x2.hpp"
#include "ValueType/Matrix2x2.hpp"



Uniform::Matrix2x2::Matrix2x2(Uniform::NameShader name_shader) : Float2x2(name_shader)
{ }

void Uniform::Matrix2x2::Put(const ::Matrix2x2 & obj)
{
	PutVoid(&obj);
}
