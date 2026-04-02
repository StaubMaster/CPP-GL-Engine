#ifndef  MATRIX_3_3_HPP
# define MATRIX_3_3_HPP

struct Point3D;
struct Angle;
struct EulerAngle3D;

struct Matrix3x3
{
	public:
	float Data[3][3];

	public:
	~Matrix3x3();
	Matrix3x3();
	
	Matrix3x3(const Matrix3x3 & other);
	Matrix3x3 & operator=(const Matrix3x3 & other);

	Matrix3x3(	float data00, float data01, float data02,
				float data10, float data11, float data12,
				float data20, float data21, float data22);

	Matrix3x3	ToTranspose() const;
	Matrix3x3	operator~() const;

	static Matrix3x3	Identity();
	static Matrix3x3	RotationX(Angle a);
	static Matrix3x3	RotationY(Angle a);
	static Matrix3x3	RotationZ(Angle a);
	static Matrix3x3	Rotation(EulerAngle3D a);

	public:
	Matrix3x3	operator*(const Matrix3x3 & other) const;
	Matrix3x3	operator/(const Matrix3x3 & other) const;
};

Point3D	operator*(const Point3D & p, const Matrix3x3 & mat);
Point3D	operator/(const Point3D & p, const Matrix3x3 & mat);

#endif