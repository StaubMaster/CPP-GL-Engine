#include "Graphics/Uniform/Trans2D.hpp"
#include "ValueType/Trans2D.hpp"



Uniform::Trans2D::Trans2D(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Pos(shader, name + ".Pos")
	, Rot(shader, name + ".Rot")
{ }



void Uniform::Trans2D::Put(const ::Trans2D & obj)
{
	Pos.Put(obj.Pos);
	Rot.Put(obj.Rot);
}
