#ifndef  VECTOR_I_2_HPP
# define VECTOR_I_2_HPP

# include "ValueType/Vector/_2.hpp"

struct VectorF2;
struct VectorU2;

struct VectorI2 : public Vector_2<int, VectorI2>
{
	~VectorI2();

	VectorI2();
	VectorI2(int value);
	VectorI2(int x, int y);

	VectorI2(const VectorF2 & other);
	VectorI2(const VectorU2 & other);
	VectorI2(const VectorI2 & other);

	VectorI2 & operator=(const VectorF2 & other);
	VectorI2 & operator=(const VectorU2 & other);
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
};

VectorI2		operator+(VectorI2 vec, int val);
VectorI2		operator-(VectorI2 vec, int val);
VectorI2		operator*(VectorI2 vec, int val);
VectorI2		operator/(VectorI2 vec, int val);

VectorI2		operator+(int val, VectorI2 vec);
VectorI2		operator-(int val, VectorI2 vec);
VectorI2		operator*(int val, VectorI2 vec);
VectorI2		operator/(int val, VectorI2 vec);

#endif