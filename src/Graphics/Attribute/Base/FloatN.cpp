#include "Graphics/Attribute/Base/FloatN.hpp"
#include "OpenGLEnums.hpp"



Attribute::FloatN::~FloatN() { }

Attribute::FloatN::FloatN(Buffer::Array & buffer, unsigned int size0, unsigned int size1)
	: Attribute::Base()
	, Location(buffer, size0, size1)
{ }

Attribute::FloatN::FloatN(const FloatN & other)
	: Attribute::Base(other)
	, Location(other.Location)
{ }
Attribute::FloatN & Attribute::FloatN::operator=(const FloatN & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::FloatN::Change(GL::AttributeLocation index)
{
	Location.Change(index);
}



void Attribute::FloatN::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
