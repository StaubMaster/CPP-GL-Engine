#ifndef  VECTOR_4_HPP
# define VECTOR_4_HPP

# include "Bool4.hpp"

template<typename ValueType, typename StructType> struct Vector_4
{
ValueType X;
ValueType Y;
ValueType Z;
ValueType W;



~Vector_4() { }

Vector_4()
	: X(0)
	, Y(0)
	, Z(0)
	, W(0)
{ }
Vector_4(ValueType value)
	: X(value)
	, Y(value)
	, Z(value)
	, W(value)
{ }
Vector_4(ValueType x, ValueType y, ValueType z, ValueType w)
	: X(x)
	, Y(y)
	, Z(z)
	, W(w)
{ }

Vector_4(const Vector_4 & other)
	: X(other.X)
	, Y(other.Y)
	, Z(other.Z)
	, W(other.W)
{ }
Vector_4 & operator=(const Vector_4 & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;
	return *this;
}



StructType		operator+() const { return StructType(+X, +Y, +Z, +W); }
StructType		operator-() const { return StructType(-X, -Y, -Z, -W); }

StructType		operator+(const StructType & other) const { return StructType(X + other.X, Y + other.Y, Z + other.Z, W + other.W); }
StructType		operator-(const StructType & other) const { return StructType(X - other.X, Y - other.Y, Z - other.Z, W - other.W); }
StructType		operator*(const StructType & other) const { return StructType(X * other.X, Y * other.Y, Z * other.Z, W * other.W); }
StructType		operator/(const StructType & other) const { return StructType(X / other.X, Y / other.Y, Z / other.Z, W / other.W); }

StructType &	operator+=(const StructType & other) { X += other.X; Y += other.Y; Z += other.Z; W += other.W; return *((StructType*)this); }
StructType &	operator-=(const StructType & other) { X -= other.X; Y -= other.Y; Z -= other.Z; W -= other.W; return *((StructType*)this); }
StructType &	operator*=(const StructType & other) { X *= other.X; Y *= other.Y; Z *= other.Z; W *= other.W; return *((StructType*)this); }
StructType &	operator/=(const StructType & other) { X /= other.X; Y /= other.Y; Z /= other.Z; W /= other.W; return *((StructType*)this); }

Bool4			operator==(const Vector_4 & other) const { return Bool4(X == other.X, Y == other.Y, Z == other.Z, W == other.W); }
Bool4			operator!=(const Vector_4 & other) const { return Bool4(X != other.X, Y != other.Y, Z != other.Z, W != other.W); }
Bool4			operator< (const Vector_4 & other) const { return Bool4(X <  other.X, Y <  other.Y, Z <  other.Z, W <  other.W); }
Bool4			operator> (const Vector_4 & other) const { return Bool4(X >  other.X, Y >  other.Y, Z >  other.Z, W >  other.W); }
Bool4			operator<=(const Vector_4 & other) const { return Bool4(X <= other.X, Y <= other.Y, Z <= other.Z, W <= other.W); }
Bool4			operator>=(const Vector_4 & other) const { return Bool4(X >= other.X, Y >= other.Y, Z >= other.Z, W >= other.W); }

StructType &	operator+=(ValueType val) { X += val; Y += val; Z += val; W += val; return *((StructType*)this); }
StructType &	operator-=(ValueType val) { X -= val; Y -= val; Z -= val; W -= val; return *((StructType*)this); }
StructType &	operator*=(ValueType val) { X *= val; Y *= val; Z *= val; W *= val; return *((StructType*)this); }
StructType &	operator/=(ValueType val) { X /= val; Y /= val; Z /= val; W /= val; return *((StructType*)this); }
};

#endif