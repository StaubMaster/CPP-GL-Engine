#ifndef  CONTAINER_BEHAVIOUR_HPP
# define CONTAINER_BEHAVIOUR_HPP

# include "Base.hpp"

namespace Container
{
//	put both into one struct ?

enum class IncreaseBehaviour
{
	None,	// Limit is constant
	Fit,	// Limit = Count
	Binary,	// use closest (n ^ 2) - 1 Limit
};
enum class DecreaseBehaviour
{
	None,	// Limit is constant
	Fit,	// Limit = Count
	Binary,	// use closest (n ^ 2) - 1 Limit
};

unsigned int BinarySize(unsigned int wanted_size);

};

#endif