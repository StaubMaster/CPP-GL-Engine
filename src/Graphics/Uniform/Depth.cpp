#include "Graphics/Uniform/Depth.hpp"
#include "DataStruct/Depth.hpp"



Uniform::Depth::Depth(Uniform::NameShader name_shader) : GBase(name_shader),
	Factors(name_shader.Suffix(".Factors")),
	Range(name_shader.Suffix(".Range")),
	Color(name_shader.Suffix(".Color"))
{ }

void Uniform::Depth::PutData(::Depth val)
{
	Factors.PutData(val.Factors);
	Range.PutData(val.Range);
	Color.PutData(val.Color);
}
