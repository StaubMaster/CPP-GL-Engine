#include "Graphics/Uniform/PixelSize.hpp"
#include "Display/PixelSize.hpp"



Uniform::PixelSize::PixelSize(std::string name)
	: GBase(name)
	, Full(Name + ".Full")
	, Half(Name + ".Half")
{ }
Uniform::PixelSize::PixelSize(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Full(layout, Name + ".Full")
	, Half(layout, Name + ".Half")
{ }



void Uniform::PixelSize::Put(const ::PixelSize & obj)
{
	Full.Put(obj.Full);
	Half.Put(obj.Half);
}
