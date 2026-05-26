#include "Graphics/Uniform/PixelSize.hpp"
#include "Display/PixelSize.hpp"



Uniform::PixelSize::PixelSize(Uniform::Layout & layout,  std::string name)
	: GBase(layout, name)
	, Full(layout, name + ".Full")
	, Half(layout, name + ".Half")
{ }



void Uniform::PixelSize::Put(const ::PixelSize & obj)
{
	Full.Put(obj.Full);
	Half.Put(obj.Half);
}
