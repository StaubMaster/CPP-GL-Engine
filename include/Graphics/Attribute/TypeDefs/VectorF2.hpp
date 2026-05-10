#ifndef  ATTRIB_VECTOR_F_2_HPP
# define ATTRIB_VECTOR_F_2_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<2, 1> VectorF2;
/*class VectorF2 : public Attribute::FloatN<2, 1>
{
	public:
	~VectorF2();
	VectorF2() = delete;
	VectorF2(Buffer::Array & buffer);

	VectorF2(const VectorF2 & other) = delete;
	VectorF2(Buffer::Array & buffer, const VectorF2 & other);
	VectorF2 & operator=(const VectorF2 & other);
};*/
typedef VectorF2 VectorF2;
};

#endif