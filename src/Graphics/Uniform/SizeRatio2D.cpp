#include "Graphics/Uniform/SizeRatio2D.hpp"
#include "Display/SizeRatio2D.hpp"



Uniform::SizeRatio2D::SizeRatio2D(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Size(shader, name + ".Size")
	, Ratio(shader, name + ".Ratio")
{ }



void Uniform::SizeRatio2D::Put(const ::SizeRatio2D & obj)
{
	Size.Put(obj.Size);
	Ratio.Put(obj.Ratio);
}
