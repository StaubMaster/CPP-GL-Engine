#include "Graphics/Uniform/Range.hpp"
#include "ValueType/Range.hpp"



Uniform::Range::Range(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Min(shader, name + ".Min")
	, Len(shader, name + ".Len")
	, Max(shader, name + ".Max")
{ }



void Uniform::Range::Put(const ::Range & obj)
{
	Min.PutVoid(&obj.Min);
	Len.PutVoid(&obj.Len);
	Max.PutVoid(&obj.Max);
}
