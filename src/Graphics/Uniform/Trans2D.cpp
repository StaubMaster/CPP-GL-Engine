#include "Graphics/Uniform/Trans2D.hpp"
#include "ValueType/Trans/2D.hpp"
#include "ValueType/Matrix/2x2.hpp"



Uniform::Trans2D::Trans2D(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Pos(layout, Name + ".Pos")
	, Rot(layout, Name + ".Rot")
{ }



void Uniform::Trans2D::Put(const ::Trans2D & obj)
{
	Pos.Put(obj.Pos);
	Rot.Put(::Matrix2x2::Rotation(obj.Rot));
}
