#include "Graphics/Uniform/Trans3D.hpp"
#include "ValueType/Trans/3D.hpp"
#include "ValueType/Matrix/3x3.hpp"



Uniform::Trans3D::Trans3D(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Pos(layout, Name + ".Pos")
	, Rot(layout, Name + ".Rot")
{ }



void Uniform::Trans3D::Put(const ::Trans3D & obj)
{
	Pos.Put(obj.Position);
	Rot.Put(~::Matrix3x3::Rotation(obj.Rotation));
}
