#ifndef  PADDED_BLOCK_TYPE_BASE_HPP
# define PADDED_BLOCK_TYPE_BASE_HPP

# include "Graphics/PaddedBlock/General/Base.hpp"

namespace PaddedBlock
{
template<typename Type, unsigned int PaddingCount>
struct TypeBase : Base
{
	Type	Value;
	float	Padding[PaddingCount];
	TypeBase & operator=(const Type & object)
	{
		Value = object;
		return *this;
	}
};
};

#endif