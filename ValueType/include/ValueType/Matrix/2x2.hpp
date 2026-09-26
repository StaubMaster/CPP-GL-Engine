#ifndef  MATRIX_2_2_HPP
# define MATRIX_2_2_HPP

struct VectorF2;
struct Angle;

struct Matrix2x2
{
	float Data[2][2] = {
		{ 0.0f, 0.0f, },
		{ 0.0f, 0.0f, },
	};

	~Matrix2x2() = default;
	Matrix2x2() = default;
	Matrix2x2(const Matrix2x2 & other) = default;
	Matrix2x2 & operator=(const Matrix2x2 & other) = default;

	Matrix2x2(	float data00, float data01,
				float data10, float data11);

	Matrix2x2	ToTranspose() const;
	Matrix2x2	operator~() const;

	static Matrix2x2	Identity();

	static Matrix2x2	Rotation(Angle a);

	Matrix2x2	operator*(const Matrix2x2 & other) const;
	Matrix2x2	operator/(const Matrix2x2 & other) const;
};

VectorF2	operator*(const VectorF2 & p, const Matrix2x2 & mat);
VectorF2	operator/(const VectorF2 & p, const Matrix2x2 & mat);

#endif