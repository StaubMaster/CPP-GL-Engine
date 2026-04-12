#ifndef  VECTOR_U_3_HPP
# define VECTOR_U_3_HPP

#include "Vector_3.hpp"

struct VectorU3 : public Vector_3<unsigned int, VectorU3>
{
	~VectorU3();

	VectorU3();
	VectorU3(unsigned int value);
	VectorU3(unsigned int x, unsigned int y, unsigned int z);

	VectorU3(const VectorU3 & other);
	VectorU3 & operator=(const VectorU3 & other);



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



	VectorU3		operator%(const VectorU3 & other) const;

	VectorU3		operator~() const;
	VectorU3		operator&(const VectorU3 & other) const;
	VectorU3		operator|(const VectorU3 & other) const;
	VectorU3		operator^(const VectorU3 & other) const;
	VectorU3		operator<<(const VectorU3 & other) const;
	VectorU3		operator>>(const VectorU3 & other) const;



	unsigned int	Product() const;
};

#endif