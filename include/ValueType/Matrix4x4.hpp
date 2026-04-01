#ifndef  MATRIX_4_4_HPP
# define MATRIX_4_4_HPP

struct Angle;
struct Point4D;

struct Point3D;
struct EulerAngle3D;

struct Matrix4x4
{
	public:
	float Data[4][4];

	public:
	~Matrix4x4();
	Matrix4x4();
	
	Matrix4x4(const Matrix4x4 & other);
	Matrix4x4 & operator=(const Matrix4x4 & other);

	Matrix4x4(	float data00, float data01, float data02, float data03,
				float data10, float data11, float data12, float data13,
				float data20, float data21, float data22, float data23,
				float data30, float data31, float data32, float data33);

	static Matrix4x4	Identity();
	static Matrix4x4	Position(Point3D p);
	static Matrix4x4	Rotation(EulerAngle3D a);

	Matrix4x4	ToTranspose() const;

	public:
	Matrix4x4	operator*(const Matrix4x4 & other) const;

	public:
	Point4D		operator*(Point4D p) const;
	Point4D		operator/(Point4D p) const;

	public:
	Point3D		operator*(Point3D p) const;
	Point3D		operator/(Point3D p) const;
};

#endif