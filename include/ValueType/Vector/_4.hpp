#ifndef  VECTOR_4_HPP
# define VECTOR_4_HPP

# include "ValueType/Bool4.hpp"

template<typename ValueType, typename VectorType> struct Vector_4
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



VectorType		Min(const VectorType & other) const
{
	VectorType vec(*this);
	if (other.X < vec.X) { vec.X = other.X; }
	if (other.Y < vec.Y) { vec.Y = other.Y; }
	if (other.Z < vec.Z) { vec.Z = other.Z; }
	if (other.W < vec.W) { vec.W = other.W; }
	return vec;
}
VectorType		Max(const VectorType & other) const
{
	VectorType vec(*this);
	if (other.X > vec.X) { vec.X = other.X; }
	if (other.Y > vec.Y) { vec.Y = other.Y; }
	if (other.Z > vec.Z) { vec.Z = other.Z; }
	if (other.W > vec.W) { vec.W = other.W; }
	return vec;
}



VectorType		operator+() const { return VectorType(+X, +Y, +Z, +W); }
VectorType		operator-() const { return VectorType(-X, -Y, -Z, -W); }

VectorType		operator+(const VectorType & other) const { return VectorType(X + other.X, Y + other.Y, Z + other.Z, W + other.W); }
VectorType		operator-(const VectorType & other) const { return VectorType(X - other.X, Y - other.Y, Z - other.Z, W - other.W); }
VectorType		operator*(const VectorType & other) const { return VectorType(X * other.X, Y * other.Y, Z * other.Z, W * other.W); }
VectorType		operator/(const VectorType & other) const { return VectorType(X / other.X, Y / other.Y, Z / other.Z, W / other.W); }

VectorType &	operator+=(const VectorType & other) { X += other.X; Y += other.Y; Z += other.Z; W += other.W; return *((VectorType*)this); }
VectorType &	operator-=(const VectorType & other) { X -= other.X; Y -= other.Y; Z -= other.Z; W -= other.W; return *((VectorType*)this); }
VectorType &	operator*=(const VectorType & other) { X *= other.X; Y *= other.Y; Z *= other.Z; W *= other.W; return *((VectorType*)this); }
VectorType &	operator/=(const VectorType & other) { X /= other.X; Y /= other.Y; Z /= other.Z; W /= other.W; return *((VectorType*)this); }

Bool4			operator==(const Vector_4 & other) const { return Bool4(X == other.X, Y == other.Y, Z == other.Z, W == other.W); }
Bool4			operator!=(const Vector_4 & other) const { return Bool4(X != other.X, Y != other.Y, Z != other.Z, W != other.W); }
Bool4			operator< (const Vector_4 & other) const { return Bool4(X <  other.X, Y <  other.Y, Z <  other.Z, W <  other.W); }
Bool4			operator> (const Vector_4 & other) const { return Bool4(X >  other.X, Y >  other.Y, Z >  other.Z, W >  other.W); }
Bool4			operator<=(const Vector_4 & other) const { return Bool4(X <= other.X, Y <= other.Y, Z <= other.Z, W <= other.W); }
Bool4			operator>=(const Vector_4 & other) const { return Bool4(X >= other.X, Y >= other.Y, Z >= other.Z, W >= other.W); }

VectorType &	operator+=(ValueType val) { X += val; Y += val; Z += val; W += val; return *((VectorType*)this); }
VectorType &	operator-=(ValueType val) { X -= val; Y -= val; Z -= val; W -= val; return *((VectorType*)this); }
VectorType &	operator*=(ValueType val) { X *= val; Y *= val; Z *= val; W *= val; return *((VectorType*)this); }
VectorType &	operator/=(ValueType val) { X /= val; Y /= val; Z /= val; W /= val; return *((VectorType*)this); }
};

#endif