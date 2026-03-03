#include "Graphics/Uniform/AspectRatio.hpp"
#include "Display/AspectRatio.hpp"



Uniform::AspectRatio::AspectRatio(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Value(shader, name)
{ }



void Uniform::AspectRatio::Put(const ::AspectRatio & obj)
{
	Value.Put(obj.Value);
}
