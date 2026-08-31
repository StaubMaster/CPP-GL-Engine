#include "Graphics/Uniform/LInter.hpp"
#include "ValueType/LInter.hpp"



Uniform::LInter::LInter(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, T0(layout, Name + ".T0")
	, T1(layout, Name + ".T1")
{ }



void Uniform::LInter::Put(const ::LInter & obj)
{
	T0.Put(obj.GetT0());
	T1.Put(obj.GetT1());
}
