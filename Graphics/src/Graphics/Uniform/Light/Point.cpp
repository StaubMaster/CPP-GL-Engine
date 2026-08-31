#include "Graphics/Uniform/Light/Point.hpp"
#include "ValueType/Light/Point.hpp"



Uniform::LightPoint::LightPoint(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Base(layout, Name + ".Base")
	, Pos(layout, Name + ".Position")
{ }



void Uniform::LightPoint::Put(const ::LightPoint & obj)
{
	Base.Put(obj.Base);
	Pos.Put(obj.Pos);
}
