#include "Miscellaneous/Container/Behaviour.hpp"



unsigned int Container::Behaviour::BinarySize(unsigned int wanted_size)
{
	for (unsigned char shift = 31; shift < 32; shift--)
	{
		unsigned int size = 0xFFFFFFFF >> shift;
		if (size >= wanted_size)
		{
			return size;
		}
	}
	return 0;
}
