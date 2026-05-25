#include "Graphics/Attribute/Base/FloatNBase.hpp"



Attribute::FloatNBase::~FloatNBase() { }
Attribute::FloatNBase::FloatNBase(Layout & layout)
	: Base(layout)
	, Index(-1)
{ }

Attribute::FloatNBase::FloatNBase(Layout & layout, const FloatNBase & other)
	: Base(layout)
	, Index(other.Index)
{ }
Attribute::FloatNBase & Attribute::FloatNBase::operator=(const FloatNBase & other)
{
	Index = other.Index;
	return *this;
}



void Attribute::FloatNBase::Change(GL::AttributeLocation index)
{
	Index = index;
}
