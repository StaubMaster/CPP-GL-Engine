#ifndef  LOOP_U_3_HPP
# define LOOP_U_3_HPP

# include "ValueType/Bool/3.hpp"
# include "ValueType/Box/U3.hpp"
# include "ValueType/Vector/U3.hpp"

struct LoopU3
{
	BoxU3	Box;
	Bool3	MinExclude;	// false means (udx >= Min); true means (udx > Min)
	Bool3	MaxExclude;	// false means (udx <= Max); true means (udx < Max)

	~LoopU3() = default;
	LoopU3() = default;
	LoopU3(const LoopU3 & other) = default;
	LoopU3 & operator=(const LoopU3 & other) = default;

	LoopU3(const VectorU3 & size);

	LoopU3(const VectorU3 & min, const VectorU3 & max);
	LoopU3(const VectorU3 & min, const VectorU3 & max, const Bool3 & minEx, const Bool3 & maxEx);

	LoopU3(const BoxU3 & box);
	LoopU3(const BoxU3 & box, const Bool3 & minEx, const Bool3 & maxEx);

	VectorU3	Min() const;
	VectorU3	Max() const;
	VectorU3	Size() const;

	Bool3	Check(const VectorU3 & udx) const;

	void	Next(VectorU3 & udx) const;
	void	Prev(VectorU3 & udx) const;
};

#endif