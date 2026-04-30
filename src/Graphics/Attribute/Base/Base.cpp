#include "Graphics/Attribute/Base/Base.hpp"
#include "Graphics/Buffer/Array.hpp"



Attribute::Base::~Base() { }

Attribute::Base::Base(Buffer::Array & buffer)
{
	buffer.Attributes.Insert(this);
}

Attribute::Base::Base(Buffer::Array & buffer, const Base & other)
{
	(void)other;
	buffer.Attributes.Insert(this);
}
Attribute::Base & Attribute::Base::operator=(const Base & other)
{
	(void)other;
	return *this;
}
