#include "Graphics/Uniform/SizeRatio2D.hpp"
#include "Display/SizeRatio2D.hpp"
#include "DataStruct/Point2D.hpp"



Uniform::SizeRatio2D::SizeRatio2D(Uniform::NameShader name_shader) : GBase(name_shader),
	Size(name_shader.Suffix(".Size")),
	Ratio(name_shader.Suffix(".Ratio"))
{ }

void Uniform::SizeRatio2D::PutData(::SizeRatio2D sr)
{
	Size.PutData(sr.Size);
	Ratio.PutData(sr.Ratio);
}
