#ifndef  VECTOR_F_3_HPP
# define VECTOR_F_3_HPP

#include "Vector_3.hpp"

struct VectorF3 : public Vector_3<float, VectorF3>
{
	~VectorF3();

	VectorF3();
	VectorF3(float value);
	VectorF3(float x, float y, float z);

	VectorF3(const VectorF3 & other);
	VectorF3 & operator=(const VectorF3 & other);



	using	Vector_3::operator+;
	using	Vector_3::operator-;
	using	Vector_3::operator*;
	using	Vector_3::operator/;

	using	Vector_3::operator+=;
	using	Vector_3::operator-=;
	using	Vector_3::operator*=;
	using	Vector_3::operator/=;

	using	Vector_3::operator==;
	using	Vector_3::operator!=;
	using	Vector_3::operator<;
	using	Vector_3::operator>;
	using	Vector_3::operator<=;
	using	Vector_3::operator>=;



	float		length2() const;
	float		length() const;

	VectorF3		normalize() const;
	VectorF3		normalize(float & len) const;
	VectorF3		operator!() const;

	VectorF3		round() const;
	VectorF3		roundC() const;
	VectorF3		roundF() const;

	VectorF3		round(float size) const;
	VectorF3		roundC(float size) const;
	VectorF3		roundF(float size) const;



			float	dot(const VectorF3 & other) const;
	static	float	dot(const VectorF3 & v0, const VectorF3 & v1);



	static	VectorF3	cross(const VectorF3 & v0, const VectorF3 & v1);
			VectorF3	cross(const VectorF3 & other) const;
};

VectorF3		operator+(VectorF3 v, float f);
VectorF3		operator-(VectorF3 v, float f);
VectorF3		operator*(VectorF3 v, float f);
VectorF3		operator/(VectorF3 v, float f);

VectorF3		operator+(float f, VectorF3 v);
VectorF3		operator-(float f, VectorF3 v);
VectorF3		operator*(float f, VectorF3 v);
VectorF3		operator/(float f, VectorF3 v);

#endif