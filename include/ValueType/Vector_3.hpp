#ifndef  VECTOR_3_HPP
# define VECTOR_3_HPP

# include "Bool3.hpp"

template<typename ValueType, typename StructType> struct Vector_3
{
ValueType X;
ValueType Y;
ValueType Z;



~Vector_3() { }

Vector_3()
	: X(0)
	, Y(0)
	, Z(0)
{ }
Vector_3(ValueType value)
	: X(value)
	, Y(value)
	, Z(value)
{ }
Vector_3(ValueType x, ValueType y, ValueType z)
	: X(x)
	, Y(y)
	, Z(z)
{ }

Vector_3(const Vector_3 & other)
	: X(other.X)
	, Y(other.Y)
	, Z(other.Z)
{ }
Vector_3 & operator=(const Vector_3 & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}

template <typename OtherType>
Vector_3(const OtherType & other)
	: X(other.X)
	, Y(other.Y)
	, Z(other.Z)
{ }
template <typename OtherType>
Vector_3 & operator=(const OtherType & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}



StructType		operator+() const { return StructType(+X, +Y, +Z); }
StructType		operator-() const { return StructType(-X, -Y, -Z); }

StructType		operator+(const StructType & other) const { return StructType(X + other.X, Y + other.Y, Z + other.Z); }
StructType		operator-(const StructType & other) const { return StructType(X - other.X, Y - other.Y, Z - other.Z); }
StructType		operator*(const StructType & other) const { return StructType(X * other.X, Y * other.Y, Z * other.Z); }
StructType		operator/(const StructType & other) const { return StructType(X / other.X, Y / other.Y, Z / other.Z); }

StructType &	operator+=(const StructType & other) { X += other.X; Y += other.Y; Z += other.Z; return *((StructType*)this); }
StructType &	operator-=(const StructType & other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *((StructType*)this); }
StructType &	operator*=(const StructType & other) { X *= other.X; Y *= other.Y; Z *= other.Z; return *((StructType*)this); }
StructType &	operator/=(const StructType & other) { X /= other.X; Y /= other.Y; Z /= other.Z; return *((StructType*)this); }

Bool3			operator==(const Vector_3 & other) const { return Bool3(X == other.X, Y == other.Y, Z == other.Z); }
Bool3			operator!=(const Vector_3 & other) const { return Bool3(X != other.X, Y != other.Y, Z != other.Z); }
Bool3			operator< (const Vector_3 & other) const { return Bool3(X <  other.X, Y <  other.Y, Z <  other.Z); }
Bool3			operator> (const Vector_3 & other) const { return Bool3(X >  other.X, Y >  other.Y, Z >  other.Z); }
Bool3			operator<=(const Vector_3 & other) const { return Bool3(X <= other.X, Y <= other.Y, Z <= other.Z); }
Bool3			operator>=(const Vector_3 & other) const { return Bool3(X >= other.X, Y >= other.Y, Z >= other.Z); }

StructType &	operator+=(ValueType val) { X += val; Y += val; Z += val; return *((StructType*)this); }
StructType &	operator-=(ValueType val) { X -= val; Y -= val; Z -= val; return *((StructType*)this); }
StructType &	operator*=(ValueType val) { X *= val; Y *= val; Z *= val; return *((StructType*)this); }
StructType &	operator/=(ValueType val) { X /= val; Y /= val; Z /= val; return *((StructType*)this); }

StructType	Mix(const Vector_3 & other, Bool3 take) const
{
	StructType vec(*this);
	if (take.GetX()) { vec.X = other.X; }
	if (take.GetY()) { vec.Y = other.Y; }
	if (take.GetZ()) { vec.Z = other.Z; }
	return vec;
}

StructType	Min(const Vector_3 & other) const
{
	StructType vec;
	if (vec.X > other.X) { vec.X = other.X; } else { vec.X = X; }
	if (vec.Y > other.Y) { vec.Y = other.Y; } else { vec.Y = Y; }
	if (vec.Z > other.Z) { vec.Z = other.Z; } else { vec.Z = Z; }
	return vec;
}
StructType	Max(const Vector_3 & other) const
{
	StructType vec;
	if (vec.X < other.X) { vec.X = other.X; } else { vec.X = X; }
	if (vec.Y < other.Y) { vec.Y = other.Y; } else { vec.Y = Y; }
	if (vec.Z < other.Z) { vec.Z = other.Z; } else { vec.Z = Z; }
	return vec;
}

};

#endif