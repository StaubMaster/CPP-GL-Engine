#include "Graphics/Attribute/Base/FloatNBase.hpp"



Attribute::FloatNBase::~FloatNBase() { }
Attribute::FloatNBase::FloatNBase(Buffer::Array & buffer)
	: Base(buffer)
	, Index(-1)
{ }

Attribute::FloatNBase::FloatNBase(Buffer::Array & buffer, const FloatNBase & other)
	: Base(buffer)
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
