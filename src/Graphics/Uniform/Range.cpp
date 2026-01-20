#include "Graphics/Uniform/Range.hpp"
#include "ValueType/Range.hpp"



Uniform::Range::Range(Uniform::NameShader name_shader) : GBase(name_shader),
	Min(name_shader.Suffix(".Min")),
	Len(name_shader.Suffix(".Len")),
	Max(name_shader.Suffix(".Max"))
{ }



void Uniform::Range::Put(const ::Range & obj)
{
	Min.PutVoid(&obj.Min);
	Len.PutVoid(&obj.Len);
	Max.PutVoid(&obj.Max);
}
