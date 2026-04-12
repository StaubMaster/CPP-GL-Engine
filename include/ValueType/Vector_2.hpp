#ifndef  VECTOR_2_HPP
# define VECTOR_2_HPP

# include "Bool2.hpp"

template<typename ValueType, typename StructType> struct Vector_2
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



StructType		operator+() const { return StructType(+X, +Y); }
StructType		operator-() const { return StructType(-X, -Y); }

StructType		operator+(const StructType & other) const { return StructType(X + other.X, Y + other.Y); }
StructType		operator-(const StructType & other) const { return StructType(X - other.X, Y - other.Y); }
StructType		operator*(const StructType & other) const { return StructType(X * other.X, Y * other.Y); }
StructType		operator/(const StructType & other) const { return StructType(X / other.X, Y / other.Y); }

StructType &	operator+=(const StructType & other) { X += other.X; Y += other.X; return *((StructType*)this); }
StructType &	operator-=(const StructType & other) { X -= other.X; Y -= other.X; return *((StructType*)this); }
StructType &	operator*=(const StructType & other) { X *= other.X; Y *= other.X; return *((StructType*)this); }
StructType &	operator/=(const StructType & other) { X /= other.X; Y /= other.X; return *((StructType*)this); }

Bool2			operator==(const Vector_2 & other) const { return Bool2(X == other.X, Y == other.Y); }
Bool2			operator!=(const Vector_2 & other) const { return Bool2(X != other.X, Y != other.Y); }
Bool2			operator< (const Vector_2 & other) const { return Bool2(X <  other.X, Y <  other.Y); }
Bool2			operator> (const Vector_2 & other) const { return Bool2(X >  other.X, Y >  other.Y); }
Bool2			operator<=(const Vector_2 & other) const { return Bool2(X <= other.X, Y <= other.Y); }
Bool2			operator>=(const Vector_2 & other) const { return Bool2(X >= other.X, Y >= other.Y); }

StructType &	operator+=(ValueType val) { X += val; Y += val; return *((StructType*)this); }
StructType &	operator-=(ValueType val) { X -= val; Y -= val; return *((StructType*)this); }
StructType &	operator*=(ValueType val) { X *= val; Y *= val; return *((StructType*)this); }
StructType &	operator/=(ValueType val) { X /= val; Y /= val; return *((StructType*)this); }
};

// these cannot be made templates
// since they need to outside of the class

//template<typename ValueType, typename StructType> StructType operator+(Vector_2<ValueType, StructType> p, ValueType val) { return StructType(p.X + val, p.Y + val); }
//template<typename ValueType, typename StructType> StructType operator-(Vector_2<ValueType, StructType> p, ValueType val) { return StructType(p.X - val, p.Y - val); }
//template<typename ValueType, typename StructType> StructType operator*(Vector_2<ValueType, StructType> p, ValueType val) { return StructType(p.X * val, p.Y * val); }
//template<typename ValueType, typename StructType> StructType operator/(Vector_2<ValueType, StructType> p, ValueType val) { return StructType(p.X / val, p.Y / val); }
//
//template<typename ValueType, typename StructType> StructType operator+(ValueType val, Vector_2<ValueType, StructType> p) { return StructType(val + p.X, val + p.Y); }
//template<typename ValueType, typename StructType> StructType operator-(ValueType val, Vector_2<ValueType, StructType> p) { return StructType(val - p.X, val - p.Y); }
//template<typename ValueType, typename StructType> StructType operator*(ValueType val, Vector_2<ValueType, StructType> p) { return StructType(val * p.X, val * p.Y); }
//template<typename ValueType, typename StructType> StructType operator/(ValueType val, Vector_2<ValueType, StructType> p) { return StructType(val / p.X, val / p.Y); }

#endif