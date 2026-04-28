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
		+pos.Normal.Rel.X / Ratio.Value.X,
		-pos.Normal.Rel.Y / Ratio.Value.Y
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



DisplayPosition DisplaySize::PosFromWindowFull(VectorF2 pos) const
{
	DisplayPosition display_pos;
	display_pos.Window = Window.PosFromFull(pos);
	display_pos.Normal = Window.Convert(display_pos.Window);
	display_pos.Buffer = Buffer.Convert(display_pos.Normal);
	return display_pos;
}
DisplayPosition DisplaySize::PosFromBufferFull(VectorF2 pos) const
{
	DisplayPosition display_pos;
	display_pos.Buffer = Buffer.PosFromFull(pos);
	display_pos.Normal = Buffer.Convert(display_pos.Buffer);
	display_pos.Window = Window.Convert(display_pos.Normal);
	return display_pos;
}
DisplayPosition DisplaySize::PosFromNormalAbs(VectorF2 pos) const
{
	DisplayPosition display_pos;
	display_pos.Normal = NormalPosition::FromAbs(pos);
	display_pos.Window = Window.Convert(display_pos.Normal);
	display_pos.Buffer = Buffer.Convert(display_pos.Normal);
	return display_pos;
}
DisplayPosition DisplaySize::PosFromNormalRel(VectorF2 pos) const
{
	DisplayPosition display_pos;
	display_pos.Normal = NormalPosition::FromRel(pos);
	display_pos.Window = Window.Convert(display_pos.Normal);
	display_pos.Buffer = Buffer.Convert(display_pos.Normal);
	return display_pos;
}



