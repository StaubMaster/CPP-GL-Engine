#include "Graphics/Uniform/LightSolar.hpp"
#include "ValueType/LightSolar.hpp"



Uniform::LightSolar::LightSolar(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Base(layout, Name + ".Base")
	, Dir(layout, Name + ".Direction")
{ }



void Uniform::LightSolar::Put(const ::LightSolar & obj)
{
	Base.Put(obj.Base);
	Dir.Put(obj.Dir);
}
