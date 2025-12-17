#include "Graphics/Uniform/SizeRatio2D.hpp"
#include "Display/SizeRatio2D.hpp"
#include "DataStruct/Point2D.hpp"



Uniform::SizeRatio2D::SizeRatio2D(std::string name, Shader::Base & shader) : GBase(name, shader),
	Size(name + ".Size", shader),
	Ratio(name + ".Ratio", shader)
{

}

void Uniform::SizeRatio2D::PutData(::SizeRatio2D sr)
{
	Size.PutData(sr.Size);
	Ratio.PutData(sr.Ratio);
}
