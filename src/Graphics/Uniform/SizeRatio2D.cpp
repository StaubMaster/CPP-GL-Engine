#include "Graphics/Uniform/SizeRatio2D.hpp"
#include "Display/SizeRatio2D.hpp"



Uniform::SizeRatio2D::SizeRatio2D(Uniform::NameShader name_shader) : GBase(name_shader),
	Size(name_shader.Suffix(".Size")),
	Ratio(name_shader.Suffix(".Ratio"))
{ }



void Uniform::SizeRatio2D::Put(const ::SizeRatio2D & obj)
{
	Size.Put(obj.Size);
	Ratio.Put(obj.Ratio);
}
