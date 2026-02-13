#include "Graphics/Uniform/Trans2D.hpp"
#include "ValueType/Trans2D.hpp"



Uniform::Trans2D::Trans2D(Uniform::NameShader name_shader) : GBase(name_shader),
	Pos(name_shader.Suffix(".Pos")),
	Rot(name_shader.Suffix(".Rot"))
{ }



void Uniform::Trans2D::Put(const ::Trans2D & obj)
{
	Pos.Put(obj.Pos);
	Rot.Put(obj.Rot);
}
