#ifndef  VECTOR_U_2_HPP
# define VECTOR_U_2_HPP

#include "Vector_2.hpp"

struct VectorF2;
struct VectorI2;

struct VectorU2 : public Vector_2<unsigned int, VectorU2>
{
	~VectorU2();

	VectorU2();
	VectorU2(unsigned int value);
	VectorU2(unsigned int x, unsigned int y);

	VectorU2(const VectorF2 & other);
	VectorU2(const VectorU2 & other);
	VectorU2(const VectorI2 & other);

	VectorU2 & operator=(const VectorF2 & other);
	VectorU2 & operator=(const VectorU2 & other);
	VectorU2 & operator=(const VectorI2 & other);



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



	VectorU2		operator%(const VectorU2 & other) const;

	VectorU2		operator~() const;
	VectorU2		operator&(const VectorU2 & other) const;
	VectorU2		operator|(const VectorU2 & other) const;
	VectorU2		operator^(const VectorU2 & other) const;
	VectorU2		operator<<(const VectorU2 & other) const;
	VectorU2		operator>>(const VectorU2 & other) const;



	unsigned int	Product() const;

	unsigned int	Convert(VectorU2 udx) const;
	VectorU2		Convert(unsigned int udx) const;

	static unsigned int		Convert(unsigned int size, VectorU2 udx);
	static VectorU2			Convert(unsigned int size, unsigned int udx);
};

VectorU2		operator+(VectorU2 vec, unsigned int val);
VectorU2		operator-(VectorU2 vec, unsigned int val);
VectorU2		operator*(VectorU2 vec, unsigned int val);
VectorU2		operator/(VectorU2 vec, unsigned int val);

VectorU2		operator+(unsigned int val, VectorU2 vec);
VectorU2		operator-(unsigned int val, VectorU2 vec);
VectorU2		operator*(unsigned int val, VectorU2 vec);
VectorU2		operator/(unsigned int val, VectorU2 vec);

#endif