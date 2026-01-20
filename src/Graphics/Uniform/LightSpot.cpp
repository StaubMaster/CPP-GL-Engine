#include "Graphics/Uniform/LightSpot.hpp"
#include "ValueType/LightSpot.hpp"



Uniform::LightSpot::LightSpot(Uniform::NameShader name_shader) : GBase(name_shader),
	Base(name_shader.Suffix(".Base")),
	Pos(name_shader.Suffix(".Position")),
	Dir(name_shader.Suffix(".Direction")),
	Range(name_shader.Suffix(".Range"))
{ }



void Uniform::LightSpot::Put(const ::LightSpot & obj)
{
	Base.Put(obj.Base);
	Pos.Put(obj.Pos);
	Dir.Put(obj.Dir);
	Range.Put(obj.Range);
}
