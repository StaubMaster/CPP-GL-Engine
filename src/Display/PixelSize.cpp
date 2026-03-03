#include "Display/PixelSize.hpp"



PixelSize::~PixelSize()
{ }
PixelSize::PixelSize()
	: Full()
	, Half()
{ }

PixelSize::PixelSize(const PixelSize & other)
	: Full(other.Full)
	, Half(other.Half)
{ }
PixelSize & PixelSize::operator=(const PixelSize & other)
{
	Full = other.Full;
	Half = other.Half;
	return *this;
}



void PixelSize::ChangeFull(Point2D size)
{
	Full = size;
	Half = size / 2;
}

PixelSize PixelSize::FromFull(Point2D size)
{
	PixelSize pixel_size;
	pixel_size.ChangeFull(size);
	return pixel_size;
}
