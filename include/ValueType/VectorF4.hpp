#ifndef  VECTOR_F_4_HPP
# define VECTOR_F_4_HPP

#include "Vector_4.hpp"

struct VectorF4 : public Vector_4<float, VectorF4>
{
	~VectorF4();

	VectorF4();
	VectorF4(float value);
	VectorF4(float x, float y, float z, float w);

	VectorF4(const VectorF4 & other);
	VectorF4 & operator=(const VectorF4 & other);



	using	Vector_4::operator+;
	using	Vector_4::operator-;
	using	Vector_4::operator*;
	using	Vector_4::operator/;

	using	Vector_4::operator+=;
	using	Vector_4::operator-=;
	using	Vector_4::operator*=;
	using	Vector_4::operator/=;

	using	Vector_4::operator==;
	using	Vector_4::operator!=;
	using	Vector_4::operator<;
	using	Vector_4::operator>;
	using	Vector_4::operator<=;
	using	Vector_4::operator>=;



	float		length2() const;
	float		length() const;

	VectorF4		normalize() const;
	VectorF4		normalize(float & len) const;
	VectorF4		operator!() const;

	VectorF4		round() const;
	VectorF4		roundC() const;
	VectorF4		roundF() const;

	VectorF4		round(float size) const;
	VectorF4		roundC(float size) const;
	VectorF4		roundF(float size) const;



			float	dot(const VectorF4 & other) const;
	static	float	dot(const VectorF4 & v0, const VectorF4 & v1);
};

VectorF4		operator+(VectorF4 p, float f);
VectorF4		operator-(VectorF4 p, float f);
VectorF4		operator*(VectorF4 p, float f);
VectorF4		operator/(VectorF4 p, float f);

VectorF4		operator+(float f, VectorF4 p);
VectorF4		operator-(float f, VectorF4 p);
VectorF4		operator*(float f, VectorF4 p);
VectorF4		operator/(float f, VectorF4 p);

#endif