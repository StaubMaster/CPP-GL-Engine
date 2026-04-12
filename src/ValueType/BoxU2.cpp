#include "ValueType/BoxU2.hpp"



BoxU2::~BoxU2() { }

BoxU2::BoxU2()
	: Box_2(
		VectorU2(0xFFFFFFFF),
		VectorU2(0x00000000)
	)
{ }
BoxU2::BoxU2(VectorU2 min, VectorU2 max)
	: Box_2(min, max)
{ }

BoxU2::BoxU2(const BoxU2 & other)
	: Box_2(other)
{ }
BoxU2 & BoxU2::operator=(const BoxU2 & other)
{
	Box_2::operator=(other);
	return *this;
}



Bool2 BoxU2::CheckIn(VectorU2 udx) const { return IntersectInclusive(udx); }
Bool2 BoxU2::CheckEx(VectorU2 udx) const { return IntersectExclusive(udx); }
Bool2 BoxU2::CheckEdge(VectorU2 udx) const { return IntersectEdge(udx); }
