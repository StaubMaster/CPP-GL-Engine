#include "Graphics/Uniform/RangeF.hpp"
#include "ValueType/RangeF.hpp"



Uniform::RangeF::RangeF(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Min(layout, Name + ".Min")
	, Len(layout, Name + ".Len")
	, Max(layout, Name + ".Max")
{ }



void Uniform::RangeF::Put(const ::RangeF & obj)
{
	Min.Put(obj.GetMin());
	Len.Put(obj.Length());
	Max.Put(obj.GetMax());
}
