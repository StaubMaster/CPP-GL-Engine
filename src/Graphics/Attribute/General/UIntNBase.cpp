#include "Graphics/Attribute/General/UIntNBase.hpp"



Attribute::UIntNBase::~UIntNBase()
{ }

Attribute::UIntNBase & Attribute::UIntNBase::operator=(const UIntNBase & other)
{
	Index = other.Index;
	return *this;
}



Attribute::UIntNBase::UIntNBase(Layout & layout)
	: Base(layout)
	, Index(-1)
{ }
Attribute::UIntNBase::UIntNBase(Layout & layout, const UIntNBase & other)
	: Base(layout)
	, Index(other.Index)
{ }

void Attribute::UIntNBase::Change(GL::AttributeLocation index)
{
	Index = index;
}
