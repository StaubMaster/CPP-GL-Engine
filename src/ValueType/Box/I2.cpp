#include "ValueType/Box/I2.hpp"



BoxI2::~BoxI2() { }

BoxI2::BoxI2()
	: Box_2(
		VectorI2(0x7FFFFFFF),
		VectorI2(0x80000000)
	)
{ }
BoxI2::BoxI2(VectorI2 min, VectorI2 max)
	: Box_2(min, max)
{ }

BoxI2::BoxI2(const BoxI2 & other)
	: Box_2(other)
{ }
BoxI2 & BoxI2::operator=(const BoxI2 & other)
{
	Box_2::operator=(other);
	return *this;
}
