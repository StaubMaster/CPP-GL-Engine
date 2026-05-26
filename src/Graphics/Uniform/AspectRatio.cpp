#include "Graphics/Uniform/AspectRatio.hpp"
#include "Display/AspectRatio.hpp"



Uniform::AspectRatio::AspectRatio(Uniform::Layout & layout,  std::string name)
	: GBase(layout, name)
	, Value(layout, name)
{ }



void Uniform::AspectRatio::Put(const ::AspectRatio & obj)
{
	Value.Put(obj.Value);
}
