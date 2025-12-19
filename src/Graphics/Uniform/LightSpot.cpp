#include "Graphics/Uniform/LightSpot.hpp"
#include "DataStruct/LightSpot.hpp"



Uniform::LightSpot::LightSpot(Uniform::NameShader name_shader) : GBase(name_shader),
	Base(name_shader.Suffix(".Base")),
	Pos(name_shader.Suffix(".Position")),
	Dir(name_shader.Suffix(".Direction")),
	Range(name_shader.Suffix(".Range"))
{ }

void Uniform::LightSpot::PutData(::LightSpot val)
{
	Base.PutData(val.Base);
	Pos.PutData(val.Pos);
	Dir.PutData(val.Dir);
	Range.PutData(val.Range);
}
