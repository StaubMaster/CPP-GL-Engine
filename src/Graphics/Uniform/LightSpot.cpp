#include "Graphics/Uniform/LightSpot.hpp"
#include "ValueType/LightSpot.hpp"



Uniform::LightSpot::LightSpot(Uniform::Layout & layout,  std::string name)
	: GBase(layout, name)
	, Base(layout, name + ".Base")
	, Pos(layout, name + ".Position")
	, Dir(layout, name + ".Direction")
	, Range(layout, name + ".Range")
{ }



void Uniform::LightSpot::Put(const ::LightSpot & obj)
{
	Base.Put(obj.Base);
	Pos.Put(obj.Pos);
	Dir.Put(obj.Dir);
	Range.Put(obj.Range);
}
