#ifndef  LOOP_I_3_HPP
# define LOOP_I_3_HPP

# include "Bool3.hpp"
# include "VectorI3.hpp"
# include "BoxI3.hpp"

struct LoopI3
{
	public:
	BoxI3	Range;
	Bool3	MinExclude;	// false means (idx >= Min); true means (idx > Min)
	Bool3	MaxExclude;	// false means (idx <= Max); true means (idx < Max)

	public:
	~LoopI3();

	LoopI3();
	LoopI3(VectorI3 min, VectorI3 max);
	LoopI3(VectorI3 min, Bool3 minEx, VectorI3 max, Bool3 maxEx);

	LoopI3(const LoopI3 & other);
	LoopI3 & operator=(const LoopI3 & other);

	public:
	VectorI3	Min() const;
	VectorI3	Max() const;
	VectorI3	Size() const;

	public:
	Bool3		Check(VectorI3 idx) const;

	public:
	void	Next(VectorI3 & idx) const;
	void	Prev(VectorI3 & idx) const;
};

#endif