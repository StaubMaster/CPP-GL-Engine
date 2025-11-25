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

unsigned int BinarySize(unsigned int size)
{
	for (unsigned char shift = 31; shift < 32; shift--)
	{
		unsigned int new_size = 0xFFFFFFFF >> shift;
		if (new_size >= size)
		{
			return new_size;
		}
	}
	return 0;
}

};

#endif