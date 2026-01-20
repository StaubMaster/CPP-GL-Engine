#include "ValueType/SizeRatio2D.hpp"



SizeRatio2D::SizeRatio2D()
{ }
SizeRatio2D::SizeRatio2D(float w, float h) :
	Size(w, h)
{
	Calc();
}



void SizeRatio2D::Calc()
{
	if (Size.X == Size.Y)
	{
		Ratio.X = 1.0f;
		Ratio.Y = 1.0f;
	}
	else if (Size.X > Size.Y)
	{
		Ratio.X = Size.Y / Size.X;
		Ratio.Y = 1.0f;
	}
	else if (Size.X < Size.Y)
	{
		Ratio.X = 1.0f;
		Ratio.Y = Size.X / Size.Y;
	}
}
