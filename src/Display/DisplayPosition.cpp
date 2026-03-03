#include "Display/DisplayPosition.hpp"
#include "Display/DisplaySize.hpp"



DisplayPosition::~DisplayPosition()
{ }
DisplayPosition::DisplayPosition()
	: NormalAbs()
	, NormalRel()
	, Window()
	, Buffer()
{ }

DisplayPosition::DisplayPosition(const DisplayPosition & other)
	: NormalAbs(other.NormalAbs)
	, NormalRel(other.NormalRel)
	, Window(other.Window)
	, Buffer(other.Buffer)
{ }
DisplayPosition & DisplayPosition::operator=(const DisplayPosition & other)
{
	NormalAbs = other.NormalAbs;
	NormalRel = other.NormalRel;
	Window = other.Window;
	Buffer = other.Buffer;
	return *this;
}



void DisplayPosition::ChangeWindowCorner(Point2D pos, DisplaySize size)
{
	Window.Corner = pos;
	Window.Center = Window.Corner - size.Window.Half;

	NormalAbs = Window.Corner / size.Window.Full;
	NormalRel = Window.Center / size.Window.Half;

	Buffer.Corner = NormalAbs * size.Buffer.Full;
	Buffer.Center = NormalRel * size.Buffer.Half;
}
void DisplayPosition::ChangeNormalRel(Point2D pos, DisplaySize size)
{
	NormalRel = pos;
	NormalAbs = (pos + 1) / 2;

	Window.Corner = NormalAbs * size.Window.Full;
	Window.Center = NormalRel * size.Window.Half;

	Buffer.Corner = NormalAbs * size.Buffer.Full;
	Buffer.Center = NormalRel * size.Buffer.Half;
}

DisplayPosition DisplayPosition::FromWindowCorner(Point2D pos, DisplaySize size)
{
	DisplayPosition display_pos;
	display_pos.ChangeWindowCorner(pos, size);
	return display_pos;
}
DisplayPosition DisplayPosition::FromNormalRel(Point2D pos, DisplaySize size)
{
	DisplayPosition display_pos;
	display_pos.ChangeNormalRel(pos, size);
	return display_pos;
}
