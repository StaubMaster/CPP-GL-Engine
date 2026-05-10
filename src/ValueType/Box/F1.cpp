#include "ValueType/Box/F1.hpp"



BoxF1::~BoxF1() { }

BoxF1::BoxF1()
	: Box_1(
		float(+1/0.0f),
		float(-1/0.0f)
	)
{ }
BoxF1::BoxF1(float min, float max)
	: Box_1(min, max)
{ }

BoxF1::BoxF1(const BoxF1 & other)
	: Box_1(other)
{ }
BoxF1 & BoxF1::operator=(const BoxF1 & other)
{
	Box_1::operator=(other);
	return *this;
}
