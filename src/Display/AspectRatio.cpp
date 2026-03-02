#include "Display/AspectRatio.hpp"


AspectRatio::AspectRatio()
{ }
AspectRatio::AspectRatio(Point2D size)
{
	Change(size);
}

void AspectRatio::Change(Point2D size)
{
	if (size.X == size.Y)
	{
		X = 1.0f;
		Y = 1.0f;
	}
	else if (size.X > size.Y)
	{
		X = size.Y / size.X;
		Y = 1.0f;
	}
	else if (size.X < size.Y)
	{
		X = 1.0f;
		Y = size.X / size.Y;
	}
	else // NAN ?
	{ }
}
