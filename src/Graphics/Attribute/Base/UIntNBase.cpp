#include "Graphics/Attribute/Base/UIntNBase.hpp"



Attribute::UIntNBase::~UIntNBase() { }
Attribute::UIntNBase::UIntNBase(Buffer::Array & buffer)
	: Base(buffer)
	, Index(-1)
{ }

Attribute::UIntNBase::UIntNBase(Buffer::Array & buffer, const UIntNBase & other)
	: Base(buffer)
	, Index(other.Index)
{ }
Attribute::UIntNBase & Attribute::UIntNBase::operator=(const UIntNBase & other)
{
	Index = other.Index;
	return *this;
}



void Attribute::UIntNBase::Change(GL::AttributeLocation index)
{
	Index = index;
}
