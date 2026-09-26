#ifndef  LOOP_U_2_HPP
# define LOOP_U_2_HPP

# include "ValueType/Bool/2.hpp"
# include "ValueType/Box/U2.hpp"
# include "ValueType/Vector/U2.hpp"

struct LoopU2
{
	BoxU2	Box;
	Bool2	MinExclude;	// false means (udx >= Min); true means (udx > Min)
	Bool2	MaxExclude;	// false means (udx <= Max); true means (udx < Max)

	~LoopU2() = default;
	LoopU2() = default;
	LoopU2(const LoopU2 & other) = default;
	LoopU2 & operator=(const LoopU2 & other) = default;

	LoopU2(const VectorU2 & size);

	LoopU2(const VectorU2 & min, const VectorU2 & max);
	LoopU2(const VectorU2 & min, const VectorU2 & max, const Bool2 & minEx, const Bool2 & maxEx);

	LoopU2(const BoxU2 & box);
	LoopU2(const BoxU2 & box, const Bool2 & minEx, const Bool2 & maxEx);

	VectorU2	Min() const;
	VectorU2	Max() const;
	VectorU2	Size() const;

	Bool2	Check(const VectorU2 & udx) const;

	void	Next(VectorU2 & udx) const;
	void	Prev(VectorU2 & udx) const;
};

#endif