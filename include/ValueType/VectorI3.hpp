#ifndef  VECTOR_I_3_HPP
# define VECTOR_I_3_HPP

#include "Vector_3.hpp"

struct VectorI3 : public Vector_3<int, VectorI3>
{
	~VectorI3();

	VectorI3();
	VectorI3(int value);
	VectorI3(int x, int y, int z);

	VectorI3(const VectorI3 & other);
	VectorI3 & operator=(const VectorI3 & other);



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



	VectorI3		operator%(const VectorI3 & other) const;

	VectorI3		operator~() const;
	VectorI3		operator&(const VectorI3 & other) const;
	VectorI3		operator|(const VectorI3 & other) const;
	VectorI3		operator^(const VectorI3 & other) const;
	VectorI3		operator<<(const VectorI3 & other) const;
	VectorI3		operator>>(const VectorI3 & other) const;



	int	Product() const;

	unsigned int	Convert(VectorI3 idx) const;
	VectorI3		Convert(unsigned int idx) const;

	static unsigned int		Convert(unsigned int size, VectorI3 idx);
	static VectorI3			Convert(unsigned int size, unsigned int idx);
};

#endif