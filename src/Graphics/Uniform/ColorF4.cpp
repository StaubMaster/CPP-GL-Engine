#include "Graphics/Uniform/ColorF4.hpp"
#include "ValueType/ColorF4.hpp"



Uniform::ColorF4::ColorF4(Uniform::NameShader name_shader) : Float4(name_shader)
{ }

void Uniform::ColorF4::Put(const ::ColorF4 & obj)
{
	PutVoid(&obj);
}
