#include "Graphics/Uniform/Color.hpp"
#include "DataStruct/Color.hpp"



Uniform::Color::Color(Uniform::NameShader name_shader) : Float3(name_shader)
{ }

void Uniform::Color::Put(const ::Color & val)
{
	PutVoid(&val);
}
