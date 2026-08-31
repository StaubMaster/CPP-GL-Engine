#include "Graphics/Attribute/General/Base.hpp"
#include "Graphics/Attribute/General/Layout.hpp"



Attribute::Base::~Base()
{ }

Attribute::Base & Attribute::Base::operator=(const Base & other)
{
	(void)other;
	return *this;
}



Attribute::Base::Base(Layout & layout)
{
	layout.Put(this);
}
Attribute::Base::Base(Layout & layout, const Base & other)
{
	(void)other;
	layout.Put(this);
}
