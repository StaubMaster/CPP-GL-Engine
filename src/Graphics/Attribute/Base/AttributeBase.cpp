#include "Graphics/Attribute/Base/AttributeBase.hpp"



Attribute::Base::Base() { }
Attribute::Base::~Base() { }

Attribute::Base::Base(const Base & other)
{
	(void)other;
}
Attribute::Base & Attribute::Base::operator=(const Base & other)
{
	(void)other;
	return *this;
}
