#include "Graphics/Attribute/Base/IntNBase.hpp"



Attribute::IntNBase::~IntNBase() { }
Attribute::IntNBase::IntNBase(Buffer::Array & buffer)
	: Base(buffer)
	, Index(-1)
{ }

Attribute::IntNBase::IntNBase(Buffer::Array & buffer, const IntNBase & other)
	: Base(buffer)
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
