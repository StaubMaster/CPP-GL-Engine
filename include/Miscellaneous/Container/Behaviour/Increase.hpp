#ifndef  CONTAINER_BEHAVIOUR_INCREASE_HPP
# define CONTAINER_BEHAVIOUR_INCREASE_HPP

# include "Member.hpp"

namespace Container
{
namespace Behaviour
{
enum class EIncrease
{
	None,	// Limit is constant
	Fit,	// Limit = Count
	Binary,	// use closest (n ^ 2) - 1 Limit
};

unsigned int BinarySize(unsigned int wanted_size);

template<typename T>
unsigned int IncreaseLimit(EIncrease increase, Member<T> & member, unsigned int wanted_count)
{
	if (increase == EIncrease::None)	{ return member.Limit; }
	if (increase == EIncrease::Fit)		{ return wanted_count; }
	if (increase == EIncrease::Binary)	{ return BinarySize(wanted_count); }
	return member.Limit;
}

};
};


#endif