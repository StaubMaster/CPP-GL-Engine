#include "Graphics/Uniform/Depth.hpp"
#include "DataStruct/Depth.hpp"



Uniform::Depth::Depth(Uniform::NameShader name_shader) : GBase(name_shader),
	Factors(name_shader.Suffix(".Factors")),
	Range(name_shader.Suffix(".Range")),
	Color(name_shader.Suffix(".Color"))
{ }



void Uniform::Depth::Put(const ::Depth & obj)
{
	Factors.Put(obj.Factors);
	Range.Put(obj.Range);
	Color.Put(obj.Color);
}
