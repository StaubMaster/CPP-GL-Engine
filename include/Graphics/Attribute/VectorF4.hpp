#ifndef  ATTRIB_VECTOR_F_4_HPP
# define ATTRIB_VECTOR_F_4_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class VectorF4 : public Attribute::FloatN
{
	public:
	~VectorF4();
	VectorF4() = delete;
	VectorF4(Buffer::Array & buffer);

	VectorF4(const VectorF4 & other);
	VectorF4 & operator=(const VectorF4 & other);
};
typedef VectorF4 Point4D;
};

#endif