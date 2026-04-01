#include "ValueType/Matrix4x4.hpp"
#include "ValueType/Point4D.hpp"
#include "ValueType/Angle.hpp"
#include "ValueType/EulerAngle3D.hpp"

#include "ValueType/Point3D.hpp"
#include "ValueType/Matrix3x3.hpp"



Matrix4x4::~Matrix4x4()
{ }
Matrix4x4::Matrix4x4()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			Data[x][y] = 0;
		}
	}
}

Matrix4x4::Matrix4x4(const Matrix4x4 & other)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
}
Matrix4x4 & Matrix4x4::operator=(const Matrix4x4 & other)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
	return *this;
}

Matrix4x4::Matrix4x4(	float data00, float data01, float data02, float data03,
						float data10, float data11, float data12, float data13,
						float data20, float data21, float data22, float data23,
						float data30, float data31, float data32, float data33)
{
	Data[0][0] = data00;
	Data[0][1] = data01;
	Data[0][2] = data02;
	Data[0][3] = data03;

	Data[1][0] = data10;
	Data[1][1] = data11;
	Data[1][2] = data12;
	Data[1][3] = data13;

	Data[2][0] = data20;
	Data[2][1] = data21;
	Data[2][2] = data22;
	Data[2][3] = data23;

	Data[3][0] = data30;
	Data[3][1] = data31;
	Data[3][2] = data32;
	Data[3][3] = data33;
}



Matrix4x4 Matrix4x4::ToTranspose() const
{
	Matrix4x4 mat;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			mat.Data[x][y] = Data[y][x];
		}
	}
	return mat;
}

Matrix4x4 Matrix4x4::Identity()
{
	Matrix4x4 mat;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			mat.Data[x][y] = (x == y);
		}
	}
	return mat;
}
Matrix4x4 Matrix4x4::Position(Point3D p)
{
	return Matrix4x4(
		1, 0, 0, p.X,
		0, 1, 0, p.Y,
		0, 0, 1, p.Z,
		0, 0, 0, 1
	);
}
Matrix4x4 Matrix4x4::Rotation(EulerAngle3D a)
{
	Matrix3x3 mat = Matrix3x3::Rotation(a);
	return Matrix4x4(
		mat.Data[0][0], mat.Data[0][1], mat.Data[0][2], 0,
		mat.Data[1][0], mat.Data[1][1], mat.Data[1][2], 0,
		mat.Data[2][0], mat.Data[2][1], mat.Data[2][2], 0,
		0, 0, 0, 1
	);
}



Matrix4x4 Matrix4x4::operator*(const Matrix4x4 & other) const
{
	Matrix4x4 mat;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
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



Point4D Matrix4x4::operator*(Point4D p) const
{
	float flt[4] = { p.X, p.Y, p.Z, p.W };
	float n[4];
	for (int x = 0; x < 4; x++)
	{
		float sum = 0;
		for (int y = 0; y < 4; y++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[x] = sum;
	}
	return Point4D(n[0], n[1], n[2], n[3]);
}
Point4D Matrix4x4::operator/(Point4D p) const
{
	float flt[4] = { p.X, p.Y, p.Z, p.W };
	float n[4];
	for (int y = 0; y < 4; y++)
	{
		float sum = 0;
		for (int x = 0; x < 4; x++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[y] = sum;
	}
	return Point4D(n[0], n[1], n[2], n[3]);
}
