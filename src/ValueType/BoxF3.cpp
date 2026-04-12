#include "ValueType/BoxF3.hpp"



BoxF3::~BoxF3() { }

BoxF3::BoxF3()
	: Box_3(
		VectorF3(+1/0.0f),
		VectorF3(-1/0.0f)
	)
{ }
BoxF3::BoxF3(VectorF3 min, VectorF3 max)
	: Box_3(min, max)
{ }

BoxF3::BoxF3(const BoxF3 & other)
	: Box_3(other)
{ }
BoxF3 & BoxF3::operator=(const BoxF3 & other)
{
	Box_3::operator=(other);
	return *this;
}
