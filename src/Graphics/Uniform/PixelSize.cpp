#include "Graphics/Uniform/PixelSize.hpp"
#include "Display/PixelSize.hpp"



Uniform::PixelSize::PixelSize(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Full(shader, name + ".Full")
	, Half(shader, name + ".Half")
{ }



void Uniform::PixelSize::Put(const ::PixelSize & obj)
{
	Full.Put(obj.Full);
	Half.Put(obj.Half);
}
