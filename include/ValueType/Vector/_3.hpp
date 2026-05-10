#ifndef  VECTOR_3_HPP
# define VECTOR_3_HPP

# include "ValueType/Bool3.hpp"

template<typename ValueType, typename VectorType> struct Vector_3
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
/*Vector_3(ValueType value)
	: X(value)
	, Y(value)
	, Z(value)
{ }*/
Vector_3(float value)
	: X(value)
	, Y(value)
	, Z(value)
{ }
Vector_3(unsigned int value)
	: X(value)
	, Y(value)
	, Z(value)
{ }
Vector_3(int value)
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

template<typename OtherVectorType>
Vector_3(const OtherVectorType & other)
	: X(other.X)
	, Y(other.Y)
	, Z(other.Z)
{ }
template<typename OtherVectorType>
VectorType & operator=(const OtherVectorType & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *((VectorType*)this);
}



VectorType		Min(const VectorType & other) const
{
	VectorType vec(*this);
	if (other.X < vec.X) { vec.X = other.X; }
	if (other.Y < vec.Y) { vec.Y = other.Y; }
	if (other.Z < vec.Z) { vec.Z = other.Z; }
	return vec;
}
VectorType		Max(const VectorType & other) const
{
	VectorType vec(*this);
	if (other.X > vec.X) { vec.X = other.X; }
	if (other.Y > vec.Y) { vec.Y = other.Y; }
	if (other.Z > vec.Z) { vec.Z = other.Z; }
	return vec;
}




VectorType		operator+() const { return VectorType(+X, +Y, +Z); }
VectorType		operator-() const { return VectorType(-X, -Y, -Z); }

VectorType		operator+(const VectorType & other) const { return VectorType(X + other.X, Y + other.Y, Z + other.Z); }
VectorType		operator-(const VectorType & other) const { return VectorType(X - other.X, Y - other.Y, Z - other.Z); }
VectorType		operator*(const VectorType & other) const { return VectorType(X * other.X, Y * other.Y, Z * other.Z); }
VectorType		operator/(const VectorType & other) const { return VectorType(X / other.X, Y / other.Y, Z / other.Z); }

VectorType &	operator+=(const VectorType & other) { X += other.X; Y += other.Y; Z += other.Z; return *((VectorType*)this); }
VectorType &	operator-=(const VectorType & other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *((VectorType*)this); }
VectorType &	operator*=(const VectorType & other) { X *= other.X; Y *= other.Y; Z *= other.Z; return *((VectorType*)this); }
VectorType &	operator/=(const VectorType & other) { X /= other.X; Y /= other.Y; Z /= other.Z; return *((VectorType*)this); }

Bool3			operator==(const Vector_3 & other) const { return Bool3(X == other.X, Y == other.Y, Z == other.Z); }
Bool3			operator!=(const Vector_3 & other) const { return Bool3(X != other.X, Y != other.Y, Z != other.Z); }
Bool3			operator< (const Vector_3 & other) const { return Bool3(X <  other.X, Y <  other.Y, Z <  other.Z); }
Bool3			operator> (const Vector_3 & other) const { return Bool3(X >  other.X, Y >  other.Y, Z >  other.Z); }
Bool3			operator<=(const Vector_3 & other) const { return Bool3(X <= other.X, Y <= other.Y, Z <= other.Z); }
Bool3			operator>=(const Vector_3 & other) const { return Bool3(X >= other.X, Y >= other.Y, Z >= other.Z); }

VectorType &	operator+=(ValueType val) { X += val; Y += val; Z += val; return *((VectorType*)this); }
VectorType &	operator-=(ValueType val) { X -= val; Y -= val; Z -= val; return *((VectorType*)this); }
VectorType &	operator*=(ValueType val) { X *= val; Y *= val; Z *= val; return *((VectorType*)this); }
VectorType &	operator/=(ValueType val) { X /= val; Y /= val; Z /= val; return *((VectorType*)this); }

VectorType	Mix(const Vector_3 & other, Bool3 take) const
{
	VectorType vec(*this);
	if (take.GetX()) { vec.X = other.X; }
	if (take.GetY()) { vec.Y = other.Y; }
	if (take.GetZ()) { vec.Z = other.Z; }
	return vec;
}
static VectorType	Mix(Bool3 take, const Vector_3 & value_true, const Vector_3 & value_false)
{
	VectorType vec;
	if (take.GetX()) { vec.X = value_true.X; } else { vec.X = value_false.X; }
	if (take.GetY()) { vec.Y = value_true.Y; } else { vec.Y = value_false.Y; }
	if (take.GetZ()) { vec.Z = value_true.Z; } else { vec.Z = value_false.Z; }
	return vec;
}

};

#endif