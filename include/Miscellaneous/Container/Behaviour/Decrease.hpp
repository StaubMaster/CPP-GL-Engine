#ifndef  CONTAINER_BEHAVIOUR_DeCREASE_HPP
# define CONTAINER_BEHAVIOUR_DeCREASE_HPP

# include "Member.hpp"

namespace Container
{
namespace Behaviour
{
enum class EDecrease
{
	None,	// Limit is constant
	Fit,	// Limit = Count
	Binary,	// use closest (n ^ 2) - 1 Limit
};

unsigned int BinarySize(unsigned int wanted_size);

template<typename T>
unsigned int DecreaseLimit(EDecrease decrease, Member<T> & member, unsigned int wanted_count)
{
	if (decrease == EDecrease::None)	{ return member.Limit; }
	if (decrease == EDecrease::Fit)		{ return wanted_count; }
	if (decrease == EDecrease::Binary)	{ return BinarySize(wanted_count); }
	return member.Limit;
}

};
};


#endif