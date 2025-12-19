#include "Graphics/Uniform/LightSolar.hpp"
#include "DataStruct/LightSolar.hpp"



Uniform::LightSolar::LightSolar(Uniform::NameShader name_shader) : GBase(name_shader),
	Base(name_shader.Suffix(".Base")),
	Dir(name_shader.Suffix(".Direction"))
{ }

void Uniform::LightSolar::PutData(::LightSolar val)
{
	Base.PutData(val.Base);
	Dir.PutData(val.Dir);
}
