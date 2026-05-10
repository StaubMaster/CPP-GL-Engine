#include "ValueType/Box/I3.hpp"



BoxI3::~BoxI3() { }

BoxI3::BoxI3()
	: Box_3(
		VectorI3(0x7FFFFFFF),
		VectorI3(0x80000000)
	)
{ }
BoxI3::BoxI3(VectorI3 min, VectorI3 max)
	: Box_3(min, max)
{ }

BoxI3::BoxI3(const BoxI3 & other)
	: Box_3(other)
{ }
BoxI3 & BoxI3::operator=(const BoxI3 & other)
{
	Box_3::operator=(other);
	return *this;
}
