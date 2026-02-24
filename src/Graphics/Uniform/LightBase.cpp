#include "Graphics/Uniform/LightBase.hpp"
#include "ValueType/LightBase.hpp"



Uniform::LightBase::LightBase(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Intensity(shader, name + ".Intensity")
	, Color(shader, name + ".Color")
{ }



void Uniform::LightBase::Put(const ::LightBase & obj)
{
	Intensity.Put(obj.Intensity);
	Color.Put(obj.Color);
}
