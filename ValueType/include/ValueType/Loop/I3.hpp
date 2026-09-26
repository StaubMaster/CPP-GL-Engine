#ifndef  LOOP_I_3_HPP
# define LOOP_I_3_HPP

# include "ValueType/Bool/3.hpp"
# include "ValueType/Box/I3.hpp"
# include "ValueType/Vector/I3.hpp"

struct LoopI3
{
	BoxI3	Box;
	Bool3	MinExclude;	// false means (idx >= Min); true means (idx > Min)
	Bool3	MaxExclude;	// false means (idx <= Max); true means (idx < Max)

	~LoopI3() = default;
	LoopI3() = default;
	LoopI3(const LoopI3 & other) = default;
	LoopI3 & operator=(const LoopI3 & other) = default;

	LoopI3(const VectorI3 & size);

	LoopI3(const VectorI3 & min, const VectorI3 & max);
	LoopI3(const VectorI3 & min, const VectorI3 & max, const Bool3 & minEx, const Bool3 & maxEx);

	LoopI3(const BoxI3 & box);
	LoopI3(const BoxI3 & box, const Bool3 & minEx, const Bool3 & maxEx);

	VectorI3	Min() const;
	VectorI3	Max() const;
	VectorI3	Size() const;

	Bool3	Check(const VectorI3 & idx) const;

	void	Next(VectorI3 & idx) const;
	void	Prev(VectorI3 & idx) const;
};

#endif