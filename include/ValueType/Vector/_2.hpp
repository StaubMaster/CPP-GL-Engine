#ifndef  VECTOR_2_HPP
# define VECTOR_2_HPP

# include "ValueType/Bool2.hpp"

template<typename ValueType, typename VectorType> struct Vector_2
{
ValueType X;
ValueType Y;



//virtual ~Vector_2() { }
~Vector_2() { }

// making Destructor virtual increases sizeof
// having it be non-virtual means that 
//  does deleting base pointer cause memory leak ?
//  the derived shouldnt hold any memory



Vector_2()
	: X(0)
	, Y(0)
{ }
Vector_2(ValueType value)
	: X(value)
	, Y(value)
{ }

Vector_2(ValueType x, ValueType y)
	: X(x)
	, Y(y)
{ }

Vector_2(const Vector_2 & other)
	: X(other.X)
	, Y(other.Y)
{ }
Vector_2 & operator=(const Vector_2 & other)
{
	X = other.X;
	Y = other.Y;
	return *this;
}

template <typename OtherType>
Vector_2(const OtherType & other)
	: X(other.X)
	, Y(other.Y)
{ }
template <typename OtherType>
Vector_2 & operator=(const OtherType & other)
{
	X = other.X;
	Y = other.Y;
	return *this;
}



VectorType		Min(const VectorType & other) const
{
	//VectorType vec(*this);
	VectorType vec(X, Y);
	if (other.X < vec.X) { vec.X = other.X; }
	if (other.Y < vec.Y) { vec.Y = other.Y; }
	return vec;
}
VectorType		Max(const VectorType & other) const
{
	//VectorType vec(*this);
	VectorType vec(X, Y);
	if (other.X > vec.X) { vec.X = other.X; }
	if (other.Y > vec.Y) { vec.Y = other.Y; }
	return vec;
}



VectorType		operator+() const { return VectorType(+X, +Y); }
VectorType		operator-() const { return VectorType(-X, -Y); }

VectorType		operator+(const VectorType & other) const { return VectorType(X + other.X, Y + other.Y); }
VectorType		operator-(const VectorType & other) const { return VectorType(X - other.X, Y - other.Y); }
VectorType		operator*(const VectorType & other) const { return VectorType(X * other.X, Y * other.Y); }
VectorType		operator/(const VectorType & other) const { return VectorType(X / other.X, Y / other.Y); }

VectorType &	operator+=(const VectorType & other) { X += other.X; Y += other.Y; return *((VectorType*)this); }
VectorType &	operator-=(const VectorType & other) { X -= other.X; Y -= other.Y; return *((VectorType*)this); }
VectorType &	operator*=(const VectorType & other) { X *= other.X; Y *= other.Y; return *((VectorType*)this); }
VectorType &	operator/=(const VectorType & other) { X /= other.X; Y /= other.Y; return *((VectorType*)this); }

Bool2			operator==(const Vector_2 & other) const { return Bool2(X == other.X, Y == other.Y); }
Bool2			operator!=(const Vector_2 & other) const { return Bool2(X != other.X, Y != other.Y); }
Bool2			operator< (const Vector_2 & other) const { return Bool2(X <  other.X, Y <  other.Y); }
Bool2			operator> (const Vector_2 & other) const { return Bool2(X >  other.X, Y >  other.Y); }
Bool2			operator<=(const Vector_2 & other) const { return Bool2(X <= other.X, Y <= other.Y); }
Bool2			operator>=(const Vector_2 & other) const { return Bool2(X >= other.X, Y >= other.Y); }

VectorType &	operator+=(ValueType val) { X += val; Y += val; return *((VectorType*)this); }
VectorType &	operator-=(ValueType val) { X -= val; Y -= val; return *((VectorType*)this); }
VectorType &	operator*=(ValueType val) { X *= val; Y *= val; return *((VectorType*)this); }
VectorType &	operator/=(ValueType val) { X /= val; Y /= val; return *((VectorType*)this); }
};

#endif