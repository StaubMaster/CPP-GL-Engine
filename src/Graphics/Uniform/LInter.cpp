#include "Graphics/Uniform/LInter.hpp"
#include "ValueType/LInter.hpp"



Uniform::LInter::LInter(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, T0(shader, name + ".T0")
	, T1(shader, name + ".T1")
{ }



void Uniform::LInter::Put(const ::LInter & obj)
{
	T0.Put(obj.GetT0());
	T1.Put(obj.GetT1());
}
