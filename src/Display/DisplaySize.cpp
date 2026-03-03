#include "Display/DisplaySize.hpp"
#include "Display/DisplayPosition.hpp"
#include "ValueType/Point2D.hpp"



DisplaySize::~DisplaySize()
{ }
DisplaySize::DisplaySize()
	: Ratio()
	, Window()
	, Buffer()
{ }

DisplaySize::DisplaySize(const DisplaySize & other)
	: Ratio(other.Ratio)
	, Window(other.Window)
	, Buffer(other.Buffer)
{ }
DisplaySize & DisplaySize::operator=(const DisplaySize & other)
{
	Ratio = other.Ratio;
	Window = other.Window;
	Buffer = other.Buffer;
	return *this;
}

DisplaySize::DisplaySize(Point2D windowSize, Point2D bufferSize)
	: Ratio(windowSize)
	, Window(PixelSize::FromFull(windowSize))
	, Buffer(PixelSize::FromFull(bufferSize))
{ }



void DisplaySize::Change(Point2D windowSize, Point2D bufferSize)
{
	Ratio.Change(windowSize);
	Window.ChangeFull(windowSize);
	Buffer.ChangeFull(bufferSize);
}



Point2D DisplaySize::Convert(DisplayPosition pos) const
{
	return Point2D(
		+pos.NormalRel.X / Ratio.Value.X,
		-pos.NormalRel.Y / Ratio.Value.Y
	);
}
DisplayPosition DisplaySize::Convert(Point2D pos) const
{
	return DisplayPosition::FromNormalRel(
		Point2D(
			+pos.X * Ratio.Value.X,
			-pos.Y * Ratio.Value.Y
		), *this
	);
}
