#ifndef  LOOP_I_2_HPP
# define LOOP_I_2_HPP

# include "Bool2D.hpp"
# include "VectorI2.hpp"
# include "BoxI2.hpp"

struct LoopI2
{
	public:
	BoxI2	Range;
	Bool2D	MinExclude;	// false means (idx >= Min); true means (idx > Min)
	Bool2D	MaxExclude;	// false means (idx <= Max); true means (idx < Max)

	public:
	~LoopI2();

	LoopI2();
	LoopI2(VectorI2 min, VectorI2 max);
	LoopI2(VectorI2 min, Bool2D minEx, VectorI2 max, Bool2D maxEx);

	LoopI2(const LoopI2 & other);
	LoopI2 & operator=(const LoopI2 & other);

	public:
	VectorI2	Min() const;
	VectorI2	Max() const;

	public:
	Bool2D		Check(VectorI2 idx) const;

	public:
	void	Next(VectorI2 & idx) const;
	void	Prev(VectorI2 & idx) const;
};

#endif