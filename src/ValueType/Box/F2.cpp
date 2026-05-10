#include "ValueType/Box/F2.hpp"



BoxF2::~BoxF2() { }

BoxF2::BoxF2()
	: Box_2(
		VectorF2(+1/0.0f),
		VectorF2(-1/0.0f)
	)
{ }
BoxF2::BoxF2(VectorF2 min, VectorF2 max)
	: Box_2(min, max)
{ }

BoxF2::BoxF2(const BoxF2 & other)
	: Box_2(other)
{ }
BoxF2 & BoxF2::operator=(const BoxF2 & other)
{
	Box_2::operator=(other);
	return *this;
}
