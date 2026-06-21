#include "Graphics/Uniform/Depth.hpp"
#include "ValueType/Depth.hpp"



Uniform::Depth::Depth(Uniform::Layout & layout, std::string name)
	: GBase(layout, name)
	, Factors(layout, Name + ".Factors")
	, Range(layout, Name + ".Range")
	, Color(layout, Name + ".Color")
{ }



void Uniform::Depth::Put(const ::Depth & obj)
{
	Factors.Put(obj.Factors);
	Range.Put(obj.Range);
	Color.Put(obj.Color);
}
