#include "Graphics/Uniform/Trans3D.hpp"
#include "ValueType/Trans3D.hpp"



Uniform::Trans3D::Trans3D(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Pos(shader, name + ".Pos")
	, Rot(shader, name + ".Rot")
{ }



void Uniform::Trans3D::Put(const ::Trans3D & obj)
{
	Pos.Put(obj.Pos);
	Rot.Put(obj.Rot);
}
