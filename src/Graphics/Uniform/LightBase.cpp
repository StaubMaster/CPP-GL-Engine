#include "Graphics/Uniform/LightBase.hpp"
#include "ValueType/LightBase.hpp"



Uniform::LightBase::LightBase(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Intensity(layout, Name + ".Intensity")
	, Color(layout, Name + ".Color")
{ }



void Uniform::LightBase::Put(const ::LightBase & obj)
{
	Intensity.Put(obj.Intensity);
	Color.Put(obj.Color);
}
