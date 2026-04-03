#include "ValueType/Angle.hpp"
#include "ValueType/Point2D.hpp"

#include <math.h>



Angle::~Angle() { }
Angle::Angle() :
	Value(0.0f)
{ }
Angle::Angle(const Angle & other) :
	Value(other.Value)
{ }
Angle & Angle::operator=(const Angle & other)
{
	Value = other.Value;
	return *this;
}



float Angle::DegreesToRadians(float val) { return val * (TAU / 360); }
float Angle::RadiansToDegrees(float val) { return val * (360 / TAU); }

Angle::Angle(float val) :
	Value(val)
{ }

Angle Angle::Radians(float val) { return Angle(val); }
Angle Angle::Degrees(float val) { return Angle(DegreesToRadians(val)); }
Angle Angle::Section(float val) { return Angle(TAU / val); }

Angle Angle::PointToX(Point2D dir)
{
	return +Angle::aTan2(dir.Y, dir.X);
}
Angle Angle::PointToY(Point2D dir)
{
	return -Angle::aTan2(dir.X, dir.Y);
}

float Angle::ToRadians() const { return Value; }
float Angle::ToDegrees() const { return RadiansToDegrees(Value); }





void Angle::clampPI()
{
	if (Value > +(PI / 2)) { Value = +(PI / 2); }
	if (Value < -(PI / 2)) { Value = -(PI / 2); }
}

Angle Angle::round(Angle size) const { return Angle(roundf(Value / size.Value) * size.Value); }
Angle Angle::roundC(Angle size) const { return Angle(ceilf(Value / size.Value) * size.Value); }
Angle Angle::roundF(Angle size) const { return Angle(floorf(Value / size.Value) * size.Value); }





float Angle::Sin() const { return sinf(Value); }
float Angle::Cos() const { return cosf(Value); }
float Angle::Tan() const { return tanf(Value); }

Angle Angle::aSin(float val) { return Angle(asinf(val)); }
Angle Angle::aCos(float val) { return Angle(acosf(val)); }
Angle Angle::aTan2(float y, float x) { return Angle(atan2f(y, x)); }





void Angle::forward(float & x, float & y) const
{
	float t;
	float _sin = Sin();
	float _cos = Cos();
	t = _cos * x - _sin * y;
	y = _cos * y + _sin * x;
	x = t;
}
void Angle::reverse(float & x, float & y) const
{
	float t;
	float _sin = Sin();
	float _cos = Cos();
	t = _cos * x + _sin * y;
	y = _cos * y - _sin * x;
	x = t;
}

Point2D Angle::forward(Point2D p) const { forward(p.X, p.Y); return p; }
Point2D Angle::reverse(Point2D p) const { reverse(p.X, p.Y); return p; }





Angle Angle::operator+() const { return Angle(+Value); }
Angle Angle::operator-() const { return Angle(-Value); }

Angle Angle::operator+(const Angle & other) const { return Angle(Value + other.Value); }
Angle Angle::operator-(const Angle & other) const { return Angle(Value - other.Value); }
Angle Angle::operator*(const Angle & other) const { return Angle(Value * other.Value); }
Angle Angle::operator/(const Angle & other) const { return Angle(Value / other.Value); }

Angle & Angle::operator+=(const Angle & other) { Value += other.Value; return *this; }
Angle & Angle::operator-=(const Angle & other) { Value -= other.Value; return *this; }
Angle & Angle::operator*=(const Angle & other) { Value *= other.Value; return *this; }
Angle & Angle::operator/=(const Angle & other) { Value /= other.Value; return *this; }



Angle & Angle::operator*=(float f) { Value *= f; return *this; }
Angle & Angle::operator/=(float f) { Value /= f; return *this; }

Angle operator*(Angle a, float f) { a *= f; return a; }
Angle operator/(Angle a, float f) { a /= f; return a; }

Angle operator*(float f, Angle a) { a *= f; return a; }
Angle operator/(float f, Angle a) { a /= f; return a; }
