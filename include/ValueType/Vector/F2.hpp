#ifndef  VECTOR_F_2_HPP
# define VECTOR_F_2_HPP

# include "ValueType/Vector/_2.hpp"

struct VectorU2;
struct VectorI2;

struct VectorF2 : public Vector_2<float, VectorF2>
{
	~VectorF2();

	VectorF2();
	VectorF2(float value);
	VectorF2(float x, float y);

	VectorF2(const VectorF2 & other);
	VectorF2(const VectorU2 & other);
	VectorF2(const VectorI2 & other);

	VectorF2 & operator=(const VectorF2 & other);
	VectorF2 & operator=(const VectorU2 & other);
	VectorF2 & operator=(const VectorI2 & other);



	using	Vector_2::operator+;
	using	Vector_2::operator-;
	using	Vector_2::operator*;
	using	Vector_2::operator/;

	using	Vector_2::operator+=;
	using	Vector_2::operator-=;
	using	Vector_2::operator*=;
	using	Vector_2::operator/=;

	using	Vector_2::operator==;
	using	Vector_2::operator!=;
	using	Vector_2::operator<;
	using	Vector_2::operator>;
	using	Vector_2::operator<=;
	using	Vector_2::operator>=;



	float		length2() const;
	float		length() const;

	VectorF2		normalize() const;
	VectorF2		normalize(float & len) const;
	VectorF2		operator!() const;

	VectorF2		round() const;
	VectorF2		roundC() const;
	VectorF2		roundF() const;

	VectorF2		round(float size) const;
	VectorF2		roundC(float size) const;
	VectorF2		roundF(float size) const;



			float	dot(const VectorF2 & other) const;
	static	float	dot(const VectorF2 & vec0, const VectorF2 & vec1);



			float	cross(const VectorF2 & other) const;
	static	float	cross(const VectorF2 & vec0, const VectorF2 & vec1);

			VectorF2	cross(float f) const;
	static	VectorF2	cross(float f, const VectorF2 & v);
	static	VectorF2	cross(const VectorF2 & v, float f);
};

VectorF2		operator+(VectorF2 v, float f);
VectorF2		operator-(VectorF2 v, float f);
VectorF2		operator*(VectorF2 v, float f);
VectorF2		operator/(VectorF2 v, float f);

VectorF2		operator+(float f, VectorF2 v);
VectorF2		operator-(float f, VectorF2 v);
VectorF2		operator*(float f, VectorF2 v);
VectorF2		operator/(float f, VectorF2 v);

#endif