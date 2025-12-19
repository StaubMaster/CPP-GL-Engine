#include "Graphics/Uniform/Color.hpp"
#include "DataStruct/Color.hpp"



Uniform::Color::Color(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(name_shader)
{ }

void Uniform::Color::PutData(::Color val)
{
	Location.PutVoid(&val);
}
