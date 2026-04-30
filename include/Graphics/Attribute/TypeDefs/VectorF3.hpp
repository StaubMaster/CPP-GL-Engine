#ifndef  ATTRIB_VECTOR_F_3_HPP
# define ATTRIB_VECTOR_F_3_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<3, 1> VectorF3;
/*class VectorF3 : public Attribute::FloatN<3, 1>
{
	public:
	~VectorF3();
	VectorF3() = delete;
	VectorF3(Buffer::Array & buffer);

	VectorF3(const VectorF3 & other) = delete;
	VectorF3(Buffer::Array & buffer, const VectorF3 & other);
	VectorF3 & operator=(const VectorF3 & other);
};*/
typedef VectorF3 Point3D;
};

#endif