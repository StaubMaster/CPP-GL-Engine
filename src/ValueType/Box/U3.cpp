#include "ValueType/Box/U3.hpp"
#include "ValueType/Bool/3.hpp"



BoxU3::BoxU3()
	: Box_3(
		VectorU3(0xFFFFFFFF),
		VectorU3(0x00000000)
	)
{ }
BoxU3::BoxU3(VectorU3 min, VectorU3 max)
	: Box_3(min, max)
{ }



Bool3 BoxU3::CheckIn(VectorU3 udx) const { return IntersectVecInclusive(udx); }
Bool3 BoxU3::CheckEx(VectorU3 udx) const { return IntersectVecExclusive(udx); }
Bool3 BoxU3::CheckEdge(VectorU3 udx) const { return IntersectVecEdge(udx); }



#include "../src/ValueType/Box/__.cpp"
#include "../src/ValueType/Box/_3.cpp"
template struct Box__<unsigned int, VectorU3, BoxU3>;
template struct Box_3<unsigned int, VectorU3, BoxU3>;
