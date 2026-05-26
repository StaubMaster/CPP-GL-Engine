#include "Graphics/Uniform/Range.hpp"
#include "ValueType/Range.hpp"



Uniform::Range::Range(Uniform::Layout & layout,  std::string name)
	: GBase(layout, name)
	, Min(layout, name + ".Min")
	, Len(layout, name + ".Len")
	, Max(layout, name + ".Max")
{ }



void Uniform::Range::Put(const ::Range & obj)
{
	Min.Put(obj.Min);
	Len.Put(obj.Len);
	Max.Put(obj.Max);
}
