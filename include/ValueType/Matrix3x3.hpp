#ifndef  MATRIX_3_3_HPP
# define MATRIX_3_3_HPP

struct Point3D;

class Matrix3x3
{
	public:
		float Data[3][3];

	public:
		Matrix3x3();
		
		Matrix3x3(const Matrix3x3 & other);
		Matrix3x3 & operator =(const Matrix3x3 & other);

		Matrix3x3(	float data00, float data01, float data02,
					float data10, float data11, float data12,
					float data20, float data21, float data22);
		static Matrix3x3 Default();

	public:
		Matrix3x3 operator*(const Matrix3x3 & other) const;

	public:
		Point3D Multiply0(const Point3D & p) const;
		Point3D Multiply1(const Point3D & p) const;

	public:
		Matrix3x3 TransPose() const;
		void ToString() const;
};

#endif