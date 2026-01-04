#include "Graphics/Uniform/Trans3D.hpp"
#include "DataStruct/Trans3D.hpp"



Uniform::Trans3D::Trans3D(Uniform::NameShader name_shader) : GBase(name_shader),
	Pos(name_shader.Suffix(".Pos")),
	Rot(name_shader.Suffix(".Rot"))
{ }



void Uniform::Trans3D::Put(const ::Trans3D & obj)
{
	Pos.Put(obj.Pos);
	Rot.Put(obj.Rot);
}
