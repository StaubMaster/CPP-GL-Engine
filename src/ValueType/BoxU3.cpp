#include "ValueType/BoxU3.hpp"



BoxU3::~BoxU3() { }

BoxU3::BoxU3()
	: Box_3(
		VectorU3(0xFFFFFFFF),
		VectorU3(0x00000000)
	)
{ }
BoxU3::BoxU3(VectorU3 min, VectorU3 max)
	: Box_3(min, max)
{ }

BoxU3::BoxU3(const BoxU3 & other)
	: Box_3(other)
{ }
BoxU3 & BoxU3::operator=(const BoxU3 & other)
{
	Box_3::operator=(other);
	return *this;
}



Bool3 BoxU3::CheckIn(VectorU3 udx) const { return IntersectInclusive(udx); }
Bool3 BoxU3::CheckEx(VectorU3 udx) const { return IntersectExclusive(udx); }
Bool3 BoxU3::CheckEdge(VectorU3 udx) const { return IntersectEdge(udx); }
