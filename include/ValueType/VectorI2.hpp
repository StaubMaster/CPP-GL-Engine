#ifndef  VECTOR_I_2_HPP
# define VECTOR_I_2_HPP

#include "Vector_2.hpp"

struct VectorI2 : public Vector_2<int, VectorI2>
{
	~VectorI2();

	VectorI2();
	VectorI2(int value);
	VectorI2(int x, int y);

	VectorI2(const VectorI2 & other);
	VectorI2 & operator=(const VectorI2 & other);



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



	VectorI2		operator%(const VectorI2 & other) const;

	VectorI2		operator~() const;
	VectorI2		operator&(const VectorI2 & other) const;
	VectorI2		operator|(const VectorI2 & other) const;
	VectorI2		operator^(const VectorI2 & other) const;
	VectorI2		operator<<(const VectorI2 & other) const;
	VectorI2		operator>>(const VectorI2 & other) const;



	int	Product() const;

	int			Convert(VectorI2 idx) const;
	VectorI2	Convert(int idx) const;

	static int			Convert(int size, VectorI2 idx);
	static VectorI2		Convert(int size, int idx);



//	static bool		Box_inclusive(VectorI2 idx, VectorI2 min, VectorI2 max);
//	static bool		Box_exclusive(VectorI2 idx, VectorI2 min, VectorI2 max);
//
//	static bool		loop_inclusive(VectorI2 & idx, VectorI2 min, VectorI2 max);
//	static bool		loop_exclusive(VectorI2 & idx, VectorI2 min, VectorI2 max);
//	static bool		loop_inclusive(VectorI2 & idx, int min, int max);
//	static bool		loop_exclusive(VectorI2 & idx, int min, int max);
};

#endif