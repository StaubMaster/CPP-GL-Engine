#include "ValueType/Bool3D.hpp"



Bool3D::Bool3D(unsigned char bits) :
	Bits(bits)
{ }
Bool3D::Bool3D() :
	Bits(0)
{ }
Bool3D::Bool3D(bool value) :
	Bits((value << 0) | (value << 1) | (value << 2))
{ }
Bool3D::Bool3D(bool x, bool y, bool z) :
	Bits((x << 0) | (y << 1) | (z << 2))
{ }
Bool3D::~Bool3D()
{ }

Bool3D::Bool3D(const Bool3D & other) :
	Bits(other.Bits)
{ }
Bool3D & Bool3D::operator=(const Bool3D & other)
{
	Bits = other.Bits;
	return *this;
}



Bool3D Bool3D::operator&(const Bool3D & other) const { return Bool3D((unsigned char)(Bits & other.Bits)); }
Bool3D Bool3D::operator|(const Bool3D & other) const { return Bool3D((unsigned char)(Bits | other.Bits)); }
Bool3D Bool3D::operator^(const Bool3D & other) const { return Bool3D((unsigned char)(Bits ^ other.Bits)); }



bool Bool3D::operator==(const Bool3D & other) const { return Bits == other.Bits; }
bool Bool3D::operator!=(const Bool3D & other) const { return Bits != other.Bits; }



bool Bool3D::operator&(bool value) const { return ((GetX() == value) & (GetY() == value) & (GetZ() == value)); }
bool Bool3D::operator|(bool value) const { return ((GetX() == value) | (GetY() == value) | (GetZ() == value)); }
bool Bool3D::operator^(bool value) const { return ((GetX() == value) ^ (GetY() == value) ^ (GetZ() == value)); }



bool Bool3D::GetX() const { return (Bits >> 0) & 1; }
bool Bool3D::GetY() const { return (Bits >> 1) & 1; }
bool Bool3D::GetZ() const { return (Bits >> 2) & 1; }

void Bool3D::SetX(bool value) { Bits = (Bits & 0b110) | (value << 0); }
void Bool3D::SetY(bool value) { Bits = (Bits & 0b101) | (value << 1); }
void Bool3D::SetZ(bool value) { Bits = (Bits & 0b011) | (value << 2); }

bool Bool3D::All(bool value) const { return ((GetX() == value) & (GetY() == value) & (GetZ() == value)); }
bool Bool3D::Any(bool value) const { return ((GetX() == value) | (GetY() == value) | (GetZ() == value)); }
