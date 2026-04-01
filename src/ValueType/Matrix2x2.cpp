#include "ValueType/Matrix2x2.hpp"
#include "ValueType/Point2D.hpp"
#include "ValueType/Angle.hpp"



Matrix2x2::~Matrix2x2()
{ }
Matrix2x2::Matrix2x2()
{
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			Data[x][y] = 0;
		}
	}
}

Matrix2x2::Matrix2x2(const Matrix2x2 & other)
{
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
}
Matrix2x2 & Matrix2x2::operator=(const Matrix2x2 & other)
{
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
	return *this;
}

Matrix2x2::Matrix2x2(	float data00, float data01,
						float data10, float data11)
{
	Data[0][0] = data00;
	Data[0][1] = data01;

	Data[1][0] = data10;
	Data[1][1] = data11;
}



Matrix2x2 Matrix2x2::ToTranspose() const
{
	Matrix2x2 mat;
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			mat.Data[x][y] = Data[y][x];
		}
	}
	return mat;
}

Matrix2x2 Matrix2x2::Identity()
{
	Matrix2x2 mat;
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			mat.Data[x][y] = (x == y);
		}
	}
	return mat;
}
Matrix2x2 Matrix2x2::Rotation(Angle a)
{
	float sin_ = a.Sin();
	float cos_ = a.Cos();
	return Matrix2x2(
		+cos_ , -sin_ ,
		+sin_ , +cos_
	);
}





Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & other) const
{
	Matrix2x2 mat;
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			float sum = 0;
			for (int n = 0; n < 2; n++)
			{
				sum += Data[x][n] * other.Data[n][y];
			}
			mat.Data[x][y] = sum;
		}
	}
	return mat;
}



Point2D Matrix2x2::operator*(Point2D p) const
{
	float flt[2] = { p.X, p.Y };
	float n[2];
	for (int x = 0; x < 2; x++)
	{
		float sum = 0;
		for (int y = 0; y < 2; y++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[x] = sum;
	}
	return Point2D(n[0], n[1]);
}
Point2D Matrix2x2::operator/(Point2D p) const
{
	float flt[2] = { p.X, p.Y };
	float n[2];
	for (int y = 0; y < 2; y++)
	{
		float sum = 0;
		for (int x = 0; x < 2; x++)
		{
			sum += Data[x][y] * flt[x];
		}
		n[y] = sum;
	}
	return Point2D(n[0], n[1]);
}
