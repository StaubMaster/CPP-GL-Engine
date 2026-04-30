#ifndef  ATTRIB_MATRIX_4_4_HPP
# define ATTRIB_MATRIX_4_4_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<4, 4> Matrix4x4;
/*class Matrix4x4 : public Attribute::FloatN<4, 4>
{
	public:
	~Matrix4x4();
	Matrix4x4() = delete;
	Matrix4x4(Buffer::Array & buffer);

	Matrix4x4(const Matrix4x4 & other) = delete;
	Matrix4x4(Buffer::Array & buffer, const Matrix4x4 & other);
	Matrix4x4 & operator=(const Matrix4x4 & other);
};*/
};

#endif