#include "ValueType/Depth.hpp"



Depth::Depth() :
	Factors(),
	Range(),
	Color()
{ }
Depth::~Depth()
{ }

Depth::Depth(const Depth & other) :
	Factors(other.Factors),
	Range(other.Range),
	Color(other.Color)
{ }
Depth & Depth::operator=(const Depth & other)
{
	Factors = other.Factors;
	Range = other.Range;
	Color = other.Color;
	return *this;
}

Depth::Depth(DepthFactors factors, ::Range range, ColorF4 color) :
	Factors(factors),
	Range(range),
	Color(color)
{ }
