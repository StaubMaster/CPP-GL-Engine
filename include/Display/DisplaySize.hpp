#ifndef  DISPLAY_DISPLAY_SIZE_HPP
# define DISPLAY_DISPLAY_SIZE_HPP

# include "AspectRatio.hpp"
# include "PixelSize.hpp"

struct DisplayPosition;

struct DisplaySize
{
	AspectRatio	Ratio;
	PixelSize	Window;
	PixelSize	Buffer;
//	Point2D		Scale;	// Window vs Buffer

	~DisplaySize();
	DisplaySize();

	DisplaySize(const DisplaySize & other);
	DisplaySize & operator=(const DisplaySize & other);

	DisplaySize(Point2D windowSize, Point2D bufferSize);

	void Change(Point2D windowSize, Point2D bufferSize);

	Point2D Convert(DisplayPosition pos) const;
	DisplayPosition Convert(Point2D pos) const;
};

#endif