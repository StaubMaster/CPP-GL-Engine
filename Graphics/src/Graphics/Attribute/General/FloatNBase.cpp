#include "Graphics/Attribute/General/FloatNBase.hpp"



Attribute::FloatNBase::~FloatNBase()
{ }

Attribute::FloatNBase & Attribute::FloatNBase::operator=(const FloatNBase & other)
{
	Index = other.Index;
	return *this;
}



Attribute::FloatNBase::FloatNBase(Layout & layout)
	: Base(layout)
	, Index(-1)
{ }
Attribute::FloatNBase::FloatNBase(Layout & layout, GL::AttributeLocation index)
	: Base(layout)
	, Index(index)
{ }
Attribute::FloatNBase::FloatNBase(Layout & layout, const FloatNBase & other)
	: Base(layout)
	, Index(other.Index)
{ }

void Attribute::FloatNBase::Change(GL::AttributeLocation index)
{
	Index = index;
}
