#include "ValueType/Matrix3x3.hpp"
#include "ValueType/Point3D.hpp"
#include "ValueType/Angle.hpp"
#include "ValueType/EulerAngle3D.hpp"

#include "ValueType/Matrix2x2.hpp"



Matrix3x3::~Matrix3x3()
{ }
Matrix3x3::Matrix3x3()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = 0;
		}
	}
}

Matrix3x3::Matrix3x3(const Matrix3x3 & other)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
}
Matrix3x3 & Matrix3x3::operator=(const Matrix3x3 & other)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
	return *this;
}

Matrix3x3::Matrix3x3(	float data00, float data01, float data02,
						float data10, float data11, float data12,
						float data20, float data21, float data22)
{
	Data[0][0] = data00;
	Data[0][1] = data01;
	Data[0][2] = data02;

	Data[1][0] = data10;
	Data[1][1] = data11;
	Data[1][2] = data12;

	Data[2][0] = data20;
	Data[2][1] = data21;
	Data[2][2] = data22;
}



Matrix3x3 Matrix3x3::ToTranspose() const
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mat.Data[x][y] = Data[y][x];
		}
	}
	return mat;
}

Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mat.Data[x][y] = (x == y);
		}
	}
	return mat;
}
Matrix3x3 Matrix3x3::RotationX(Angle a)
{
	Matrix2x2 mat = Matrix2x2::Rotation(a);
	return Matrix3x3(
		mat.Data[0][1], 0, mat.Data[0][0],
		0, 1, 0,
		mat.Data[1][1], 0, mat.Data[1][0]
	);
}
Matrix3x3 Matrix3x3::RotationY(Angle a)
{
	Matrix2x2 mat = Matrix2x2::Rotation(a);
	return Matrix3x3(
		1, 0, 0,
		0, mat.Data[0][0], mat.Data[0][1],
		0, mat.Data[1][0], mat.Data[1][1]
	);
}
Matrix3x3 Matrix3x3::RotationZ(Angle a)
{
	Matrix2x2 mat = Matrix2x2::Rotation(a);
	return Matrix3x3(
		mat.Data[0][0], mat.Data[0][1], 0,
		mat.Data[1][0], mat.Data[1][1], 0,
		0, 0, 1
	);
}
Matrix3x3 Matrix3x3::Rotation(EulerAngle3D a)
{
	Matrix3x3 mat = Identity();
	mat = mat * RotationZ(a.Z);
	mat = mat * RotationY(a.Y);
	mat = mat * RotationX(a.X);
	return mat;
}



Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & other) const
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			float sum = 0;
			for (int n = 0; n < 3; n++)
			{
				sum += Data[x][n] * other.Data[n][y];
			}
			mat.Data[x][y] = sum;
		}
	}
	return mat;
}



Point3D Matrix3x3::operator*(Point3D p) const
{
	float flt[3] = { p.X, p.Y, p.Z };
	float n[3];
	for (int x = 0; x < 3; x++)
	{
		float sum = 0;
		for (int y = 0; y < 3; y++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[x] = sum;
	}
	return Point3D(n[0], n[1], n[2]);
}
Point3D Matrix3x3::operator/(Point3D p) const
{
	float flt[3] = { p.X, p.Y, p.Z };
	float n[3];
	for (int y = 0; y < 3; y++)
	{
		float sum = 0;
		for (int x = 0; x < 3; x++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[y] = sum;
	}
	return Point3D(n[0], n[1], n[2]);
}
