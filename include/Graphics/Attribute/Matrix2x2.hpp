#ifndef  ATTRIB_MATRIX_2_2_HPP
# define ATTRIB_MATRIX_2_2_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Matrix2x2 : public Attribute::FloatN
{
	public:
	~Matrix2x2();
	Matrix2x2() = delete;
	Matrix2x2(Buffer::Array & buffer);

	Matrix2x2(const Matrix2x2 & other);
	Matrix2x2 & operator=(const Matrix2x2 & other);
};
};

#endif