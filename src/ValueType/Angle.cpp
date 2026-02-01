#include "ValueType/Angle.hpp"

#include <math.h>



Angle::Angle() :
	Value(0.0f)
{ }
Angle::~Angle()
{ }
Angle::Angle(const Angle & other) :
	Value(other.Value)
{ }
Angle & Angle::operator=(const Angle & other)
{
	Value = other.Value;
	return *this;
}

Angle::Angle(float val) :
	Value(val)
{ }



void Angle::Clamp()
{
	if (Value > +(PI / 2)) { Value = +(PI / 2); }
	if (Value < -(PI / 2)) { Value = -(PI / 2); }
}



float Angle::DegreesToRadians(float val) { return val * (TAU / 360); }
float Angle::RadiansToDegrees(float val) { return val * (360 / TAU); }

void Angle::FromRadians(float val) { Value = val; }
void Angle::FromDegrees(float val) { Value = DegreesToRadians(val); }

float Angle::ToRadians() const { return Value; }
float Angle::ToDegrees() const { return RadiansToDegrees(Value); }

Angle Angle::Radians(float val) { return Angle(val); }
Angle Angle::Degrees(float val) { return Angle(DegreesToRadians(val)); }
Angle Angle::Section(float val) { return Angle(TAU / val); }



float Angle::Sin() const { return sinf(Value); }
float Angle::Cos() const { return cosf(Value); }
float Angle::Tan() const { return tanf(Value); }

void Angle::aSin(float val) { Value = asinf(val); }
void Angle::aCos(float val) { Value = acosf(val); }
void Angle::aTan2(float x, float y) { Value = atan2f(y, x); }

Angle Angle::SaSin(float val) { return Angle(asinf(val)); }
Angle Angle::SaCos(float val) { return Angle(acosf(val)); }
Angle Angle::SaTan2(float x, float y) { return Angle(atan2f(y, x)); }





Angle Angle::operator+(const Angle & other) const { return Angle(Value + other.Value); }
Angle Angle::operator-(const Angle & other) const { return Angle(Value - other.Value); }
Angle Angle::operator*(const Angle & other) const { return Angle(Value * other.Value); }
Angle Angle::operator/(const Angle & other) const { return Angle(Value / other.Value); }

Angle Angle::operator*(const float & flt) const { return Angle(Value * flt); }
Angle Angle::operator/(const float & flt) const { return Angle(Value / flt); }

Angle & Angle::operator+=(const Angle & other) { Value += other.Value; return *this; }
Angle & Angle::operator-=(const Angle & other) { Value -= other.Value; return *this; }
Angle & Angle::operator*=(const Angle & other) { Value *= other.Value; return *this; }
Angle & Angle::operator/=(const Angle & other) { Value /= other.Value; return *this; }

Angle &	Angle::operator*=(const float & flt) { Value *= flt; return *this; }
Angle &	Angle::operator/=(const float & flt) { Value /= flt; return *this; }
