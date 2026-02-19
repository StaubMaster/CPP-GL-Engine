#include "Graphics/Uniform/LightSpot.hpp"
#include "ValueType/LightSpot.hpp"



Uniform::LightSpot::LightSpot(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Base(shader, name + ".Base")
	, Pos(shader, name + ".Position")
	, Dir(shader, name + ".Direction")
	, Range(shader, name + ".Range")
{ }



void Uniform::LightSpot::Put(const ::LightSpot & obj)
{
	Base.Put(obj.Base);
	Pos.Put(obj.Pos);
	Dir.Put(obj.Dir);
	Range.Put(obj.Range);
}
