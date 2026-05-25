#include "Graphics/Attribute/Base/IntNBase.hpp"



Attribute::IntNBase::~IntNBase() { }
Attribute::IntNBase::IntNBase(Layout & layout)
	: Base(layout)
	, Index(-1)
{ }

Attribute::IntNBase::IntNBase(Layout & layout, const IntNBase & other)
	: Base(layout)
	, Index(other.Index)
{ }
Attribute::IntNBase & Attribute::IntNBase::operator=(const IntNBase & other)
{
	Index = other.Index;
	return *this;
}



void Attribute::IntNBase::Change(GL::AttributeLocation index)
{
	Index = index;
}
