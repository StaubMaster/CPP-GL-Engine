#include "ValueType/Bool2D.hpp"



Bool2D::Bool2D(unsigned char bits) :
	Bits(bits)
{ }
Bool2D::Bool2D() :
	Bits(0)
{ }
Bool2D::Bool2D(bool value) :
	Bits((value << 0) | (value << 1))
{ }
Bool2D::Bool2D(bool x, bool y) :
	Bits((x << 0) | (y << 1))
{ }
Bool2D::~Bool2D()
{ }

Bool2D::Bool2D(const Bool2D & other) :
	Bits(other.Bits)
{ }
Bool2D & Bool2D::operator=(const Bool2D & other)
{
	Bits = other.Bits;
	return *this;
}



Bool2D Bool2D::operator&(const Bool2D & other) const { return Bool2D((unsigned char)(Bits & other.Bits)); }
Bool2D Bool2D::operator|(const Bool2D & other) const { return Bool2D((unsigned char)(Bits | other.Bits)); }
Bool2D Bool2D::operator^(const Bool2D & other) const { return Bool2D((unsigned char)(Bits ^ other.Bits)); }



bool Bool2D::operator==(const Bool2D & other) const { return Bits == other.Bits; }
bool Bool2D::operator!=(const Bool2D & other) const { return Bits != other.Bits; }



bool Bool2D::operator&(bool value) const { return ((GetX() == value) & (GetY() == value)); }
bool Bool2D::operator|(bool value) const { return ((GetX() == value) | (GetY() == value)); }
bool Bool2D::operator^(bool value) const { return ((GetX() == value) ^ (GetY() == value)); }



bool Bool2D::GetX() const { return (Bits >> 0) & 1; }
bool Bool2D::GetY() const { return (Bits >> 1) & 1; }

void Bool2D::SetX(bool value) { Bits = (Bits & 0b110) | (value << 0); }
void Bool2D::SetY(bool value) { Bits = (Bits & 0b101) | (value << 1); }

bool Bool2D::All(bool value) const { return ((GetX() == value) & (GetY() == value)); }
bool Bool2D::Any(bool value) const { return ((GetX() == value) | (GetY() == value)); }
