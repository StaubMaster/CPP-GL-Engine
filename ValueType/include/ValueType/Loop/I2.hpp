#ifndef  LOOP_I_2_HPP
# define LOOP_I_2_HPP

# include "ValueType/Bool/2.hpp"
# include "ValueType/Box/I2.hpp"
# include "ValueType/Vector/I2.hpp"

struct LoopI2
{
	BoxI2	Box;
	Bool2	MinExclude;	// false means (idx >= Min); true means (idx > Min)
	Bool2	MaxExclude;	// false means (idx <= Max); true means (idx < Max)

	~LoopI2() = default;
	LoopI2() = default;
	LoopI2(const LoopI2 & other) = default;
	LoopI2 & operator=(const LoopI2 & other) = default;

	LoopI2(const VectorI2 & size);

	LoopI2(const VectorI2 & min, const VectorI2 & max);
	LoopI2(const VectorI2 & min, const VectorI2 & max, const Bool2 & minEx, const Bool2 & maxEx);

	LoopI2(const BoxI2 & box);
	LoopI2(const BoxI2 & box, const Bool2 & minEx, const Bool2 & maxEx);

	VectorI2	Min() const;
	VectorI2	Max() const;
	VectorI2	Size() const;

	Bool2	Check(const VectorI2 & idx) const;

	void	Next(VectorI2 & idx) const;
	void	Prev(VectorI2 & idx) const;
};

#endif