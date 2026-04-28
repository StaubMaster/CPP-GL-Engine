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



	DisplayPosition		PosFromWindowFull(VectorF2 pos) const;
	DisplayPosition		PosFromBufferFull(VectorF2 pos) const;
	DisplayPosition		PosFromNormalRel(VectorF2 pos) const;
	DisplayPosition		PosFromNormalAbs(VectorF2 pos) const;

	//DisplaySize		SizeFromBufferFull(VectorF2 size) const;
	//DisplaySize		SizeFromNormalAbs(VectorF2 size) const;
	//DisplaySize		SizeFromNormalRel(VectorF2 size) const;
};

#endif