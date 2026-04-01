#ifndef  MATRIX_2_2_HPP
# define MATRIX_2_2_HPP

struct Point2D;
struct Angle;

struct Matrix2x2
{
	public:
	float Data[2][2];

	public:
	~Matrix2x2();
	Matrix2x2();

	Matrix2x2(const Matrix2x2 & other);
	Matrix2x2 & operator=(const Matrix2x2 & other);

	Matrix2x2(	float data00, float data01,
				float data10, float data11);

	Matrix2x2	ToTranspose() const;

	static Matrix2x2	Identity();
	static Matrix2x2	Rotation(Angle a);

	public:
	Matrix2x2	operator*(const Matrix2x2 & other) const;

	public:
	Point2D		operator*(Point2D p) const;
	Point2D		operator/(Point2D p) const;
};

#endif