#include "Graphics/Uniform/LInter.hpp"
#include "DataStruct/LInter.hpp"



Uniform::LInter::LInter(Uniform::NameShader name_shader) : GBase(name_shader),
	T0(name_shader.Suffix(".T0")),
	T1(name_shader.Suffix(".T1"))
{ }

void Uniform::LInter::PutData(::LInter val)
{
	T0.PutData(((const float *)&val) + 0);
	T1.PutData(((const float *)&val) + 1);
}
