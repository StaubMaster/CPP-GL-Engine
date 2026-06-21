#include "Graphics/Attribute/General/Base.hpp"
#include "Graphics/Attribute/General/Layout.hpp"



Attribute::Base::~Base() { }

Attribute::Base::Base(Layout & layout)
{
	layout.Attributes.Insert(this);
}

Attribute::Base::Base(Layout & layout, const Base & other)
{
	(void)other;
	layout.Attributes.Insert(this);
}
Attribute::Base & Attribute::Base::operator=(const Base & other)
{
	(void)other;
	return *this;
}
