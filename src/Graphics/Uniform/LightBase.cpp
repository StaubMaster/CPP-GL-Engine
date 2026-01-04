#include "Graphics/Uniform/LightBase.hpp"
#include "DataStruct/LightBase.hpp"



Uniform::LightBase::LightBase(Uniform::NameShader name_shader) : GBase(name_shader),
	Intensity(name_shader.Suffix(".Intensity")),
	Color(name_shader.Suffix(".Color"))
{ }



void Uniform::LightBase::Put(const ::LightBase & obj)
{
	Intensity.PutData(&obj.Intensity);
	Color.Put(obj.Color);
}
