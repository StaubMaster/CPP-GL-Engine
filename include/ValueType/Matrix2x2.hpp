#ifndef  MATRIX_2_2_HPP
# define MATRIX_2_2_HPP

struct Point2D;

struct Matrix2x2
{
	public:
	float Data[2][2];

	public:
	~Matrix2x2();
	Matrix2x2();

	Matrix2x2(const Matrix2x2 & other);
	Matrix2x2 & operator=(const Matrix2x2 & other);

	Matrix2x2(const float data[4]);
//	Matrix2x2(const float data[2][2]);
//	Matrix2x2(	float data00, float data01,
//				float data10, float data11);

	static Matrix2x2 Default();

	public:
	Matrix2x2 operator*(const Matrix2x2 & other) const;

	public:
	Point2D operator*(const Point2D & p) const;
	Point2D operator/(const Point2D & p) const;

	public:
	// operator! and operator~ ?
	Matrix2x2 TransPose() const;
	Matrix2x2 Inverse() const;
//	void ToString() const;
};

#endif