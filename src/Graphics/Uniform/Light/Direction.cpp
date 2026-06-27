#include "Graphics/Uniform/Light/Direction.hpp"
#include "ValueType/Light/Direction.hpp"



Uniform::LightDirection::LightDirection(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Base(layout, Name + ".Base")
	, Dir(layout, Name + ".Direction")
{ }



void Uniform::LightDirection::Put(const ::LightDirection & obj)
{
	Base.Put(obj.Base);
	Dir.Put(obj.Dir);
}
