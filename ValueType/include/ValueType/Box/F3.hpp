#ifndef  BOX_F_3_HPP
# define BOX_F_3_HPP

# include "ValueType/Bool/3.hpp"
# include "ValueType/Vector/F3.hpp"

struct BoxF3
{
	VectorF3	Min;
	VectorF3	Max;

	VectorF3	Size() const;
	VectorF3	Center() const;

	~BoxF3() = default;
	BoxF3() = default;
	BoxF3(const BoxF3 & other) = default;
	BoxF3 & operator=(const BoxF3 & other) = default;

	BoxF3(const VectorF3 & min, const VectorF3 & max);

	static BoxF3	InverseLimit();

	void	Consider(const VectorF3 & vec);
	void	Consider(const BoxF3 & box);

	Bool3	IsNormal() const;
	BoxF3	Normalize() const;

	Bool3	ContainsEdge(const VectorF3 & vec) const;
	Bool3	ContainsInclusive(const VectorF3 & vec) const;
	Bool3	ContainsExclusive(const VectorF3 & vec) const;
	Bool3	IntersectsInclusive(const BoxF3 & box) const;
	Bool3	IntersectsExclusive(const BoxF3 & box) const;
	BoxF3	OuterBox(const BoxF3 & other) const;
	BoxF3	InnerBox(const BoxF3 & other) const;



	BoxF3		operator+(const VectorF3 & vec) const;
	BoxF3		operator-(const VectorF3 & vec) const;
	BoxF3		operator*(const VectorF3 & vec) const;
	BoxF3		operator/(const VectorF3 & vec) const;
};

#endif