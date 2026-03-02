#include "Display/DisplaySize.hpp"



DisplaySize::DisplaySize()
	: Ratio()
	, Window()
	, Buffer()
{ }
DisplaySize::DisplaySize(Point2D winSize, Point2D bufSize)
	: Ratio(winSize)
	, Window()
	, Buffer()
{
	Window.Full = winSize;
	Window.Half = winSize / 2;
	Buffer.Full = bufSize;
	Buffer.Half = bufSize / 2;
}

void DisplaySize::Change(Point2D winSize, Point2D bufSize)
{
	Ratio.Change(winSize);
	Window.Full = winSize;
	Window.Half = winSize / 2;
	Buffer.Full = bufSize;
	Buffer.Half = bufSize / 2;
}
