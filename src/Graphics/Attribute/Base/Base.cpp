#include "Graphics/Attribute/Base/Base.hpp"



Attribute::Base::~Base() { }

Attribute::Base::Base() { }

Attribute::Base::Base(const Base & other)
{
	(void)other;
}
Attribute::Base & Attribute::Base::operator=(const Base & other)
{
	(void)other;
	return *this;
}
