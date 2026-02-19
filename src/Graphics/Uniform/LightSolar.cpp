#include "Graphics/Uniform/LightSolar.hpp"
#include "ValueType/LightSolar.hpp"



Uniform::LightSolar::LightSolar(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Base(shader, name + ".Base")
	, Dir(shader, name + ".Direction")
{ }



void Uniform::LightSolar::Put(const ::LightSolar & obj)
{
	Base.Put(obj.Base);
	Dir.Put(obj.Dir);
}
