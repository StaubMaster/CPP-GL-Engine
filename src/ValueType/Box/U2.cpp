#include "ValueType/Box/U2.hpp"
#include "ValueType/Bool/2.hpp"



BoxU2::BoxU2()
	: Box_2(
		VectorU2(0xFFFFFFFF),
		VectorU2(0x00000000)
	)
{ }
BoxU2::BoxU2(VectorU2 min, VectorU2 max)
	: Box_2(min, max)
{ }



Bool2 BoxU2::CheckIn(VectorU2 udx) const { return IntersectInclusive(udx); }
Bool2 BoxU2::CheckEx(VectorU2 udx) const { return IntersectExclusive(udx); }
Bool2 BoxU2::CheckEdge(VectorU2 udx) const { return IntersectEdge(udx); }



#include "../src/ValueType/Box/__.cpp"
#include "../src/ValueType/Box/_2.cpp"
template struct Box__<unsigned int, VectorU2, BoxU2>;
template struct Box_2<unsigned int, VectorU2, BoxU2>;
