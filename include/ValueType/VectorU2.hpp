#ifndef  VECTOR_U_2_HPP
# define VECTOR_U_2_HPP

#include "Vector_2.hpp"

struct VectorU2 : public Vector_2<unsigned int, VectorU2>
{
	~VectorU2();

	VectorU2();
	VectorU2(unsigned int value);
	VectorU2(unsigned int x, unsigned int y);

	VectorU2(const VectorU2 & other);
	VectorU2 & operator=(const VectorU2 & other);



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



//	static bool		Box_inclusive(VectorU2 idx, VectorU2 min, VectorU2 max);
//	static bool		Box_exclusive(VectorU2 idx, VectorU2 min, VectorU2 max);
//
//	static bool		loop_inclusive(VectorU2 & idx, VectorU2 min, VectorU2 max);
//	static bool		loop_exclusive(VectorU2 & idx, VectorU2 min, VectorU2 max);
//	static bool		loop_inclusive(VectorU2 & idx, unsigned int min, unsigned int max);
//	static bool		loop_exclusive(VectorU2 & idx, unsigned int min, unsigned int max);
};

#endif