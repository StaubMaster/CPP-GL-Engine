#include "DataStruct/Bool3D.hpp"



Bool3D::Bool3D(unsigned char bits) :
	Bits(bits)
{ }
Bool3D::Bool3D() :
	Bits(0)
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



Bool3D Bool3D::operator&(const Bool3D & other) { return Bool3D(Bits & other.Bits); }
Bool3D Bool3D::operator|(const Bool3D & other) { return Bool3D(Bits | other.Bits); }
Bool3D Bool3D::operator^(const Bool3D & other) { return Bool3D(Bits ^ other.Bits); }



bool Bool3D::operator==(const Bool3D & other) { return Bits == other.Bits; }
bool Bool3D::operator!=(const Bool3D & other) { return Bits != other.Bits; }



bool Bool3D::GetX() const { return (Bits >> 0) & 1; }
bool Bool3D::GetY() const { return (Bits >> 1) & 1; }
bool Bool3D::GetZ() const { return (Bits >> 2) & 1; }

void Bool3D::SetX(bool val) { Bits = (Bits ^ 0b110) | (val << 0); }
void Bool3D::SetY(bool val) { Bits = (Bits ^ 0b101) | (val << 1); }
void Bool3D::SetZ(bool val) { Bits = (Bits ^ 0b011) | (val << 2); }

bool Bool3D::All(bool val) const { return ((GetX() == val) & (GetY() == val) & (GetZ() == val)); }
bool Bool3D::Any(bool val) const { return ((GetX() == val) | (GetY() == val) | (GetZ() == val)); }
