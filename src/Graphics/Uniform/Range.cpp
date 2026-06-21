#include "Graphics/Uniform/Range.hpp"
#include "ValueType/Range.hpp"



Uniform::Range::Range(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Min(layout, Name + ".Min")
	, Len(layout, Name + ".Len")
	, Max(layout, Name + ".Max")
{ }



void Uniform::Range::Put(const ::Range & obj)
{
	Min.Put(obj.Min);
	Len.Put(obj.Len);
	Max.Put(obj.Max);
}
