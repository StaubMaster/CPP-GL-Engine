#include "Graphics/Uniform/Depth.hpp"
#include "ValueType/Depth.hpp"



Uniform::Depth::Depth(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Factors(shader, name + ".Factors")
	, Range(shader, name + ".Range")
	, Color(shader, name + ".Color")
{ }



void Uniform::Depth::Put(const ::Depth & obj)
{
	Factors.Put(obj.Factors);
	Range.Put(obj.Range);
	Color.Put(obj.Color);
}
