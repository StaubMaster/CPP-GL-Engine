#include "Display/SizeRatio2D.hpp"



Point2D SizeRatio2D::NormalRatio(const Point2D & Size)
{
	if (Size.X == Size.Y)
	{
		return Point2D(1.0f, 1.0f);
	}
	else if (Size.X > Size.Y)
	{
		return Point2D(Size.Y / Size.X, 1.0f);
	}
	else if (Size.X < Size.Y)
	{
		return Point2D(1.0f, Size.X / Size.Y);
	}
	return Point2D(1.0f, 1.0f);
}



SizeRatio2D::SizeRatio2D() :
	Size(),
	Ratio(Size)
{ }
SizeRatio2D::SizeRatio2D(const SizeRatio2D & other) :
	Size(other.Size),
	Ratio(other.Ratio)
{ }
SizeRatio2D::SizeRatio2D(const Point2D & size) :
	Size(size),
	Ratio(NormalRatio(Size))
{ }



SizeRatio2D & SizeRatio2D::operator=(const SizeRatio2D & other)
{
	Size = other.Size;
	Ratio = other.Ratio;
	return *this;
}

SizeRatio2D & SizeRatio2D::operator=(const Point2D & size)
{
	Size = size;
	Ratio = NormalRatio(Size);
	return *this;
}
