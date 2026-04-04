#ifndef  MATRIX_4_4_HPP
# define MATRIX_4_4_HPP

struct Angle;
struct Point4D;

struct Point3D;
struct EulerAngle3D;
struct Trans3D;

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

	public:
	Matrix4x4	ToTranspose() const;
	Matrix4x4	operator~() const;

	static Matrix4x4	Identity();

	static Matrix4x4	Position(Point3D p);
	static Matrix4x4	Rotation(EulerAngle3D a);
	static Matrix4x4	TransformForward(Trans3D t);
	static Matrix4x4	TransformReverse(Trans3D t);

	public:
	Matrix4x4	operator*(const Matrix4x4 & other) const;
	Matrix4x4	operator/(const Matrix4x4 & other) const;
};

Point4D	operator*(const Point4D & p, const Matrix4x4 & mat);
Point4D	operator/(const Point4D & p, const Matrix4x4 & mat);

Point3D	operator*(const Point3D & p, const Matrix4x4 & mat);
Point3D	operator/(const Point3D & p, const Matrix4x4 & mat);

//Point4D operator*(const Matrix4x4 & mat, const Point4D & p);
//Point4D operator/(const Matrix4x4 & mat, const Point4D & p);

#endif