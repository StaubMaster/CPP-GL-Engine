#ifndef  ATTRIB_MATRIX_3_3_HPP
# define ATTRIB_MATRIX_3_3_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<3, 3> Matrix3x3;
/*class Matrix3x3 : public Attribute::FloatN<3, 3>
{
	public:
	~Matrix3x3();
	Matrix3x3() = delete;
	Matrix3x3(Buffer::Array & buffer);

	Matrix3x3(const Matrix3x3 & other) = delete;
	Matrix3x3(Buffer::Array & buffer, const Matrix3x3 & other);
	Matrix3x3 & operator=(const Matrix3x3 & other);
};*/
};

#endif