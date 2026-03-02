#ifndef  DISPLAY_DISPLAY_SIZE_HPP
# define DISPLAY_DISPLAY_SIZE_HPP

# include "AspectRatio.hpp"
# include "PixelSize.hpp"

struct AbsNormal2D;		// AbsNormal    [ 0 ; 1 ]
struct RelNormal2D;		// RelNormal    [ -1 ; +1 ]
struct PixelCoord2D;	// PixelCoords  [ 0 ; FrameBufferSize ]
struct ScreenCoord2D;	// ScreenCoords [ 0 ; WindowSize ]
						// CenterCoords [ -n/2 ; +n/2 ]

struct DisplayPosition;

struct DisplaySize
{
	AspectRatio	Ratio;
	PixelSize	Window;
	PixelSize	Buffer;
//	Point2D		Scale;	// Window vs Buffer

	DisplaySize();
	DisplaySize(Point2D winSize, Point2D bufSize);

	void Change(Point2D winSize, Point2D bufSize);

	DisplayPosition	From_TopLeft_WindowPosition(Point2D pos) const;

//	AbsNormal2D		ToAbsNormal2D(AbsNormal2D coord);
//	AbsNormal2D		ToAbsNormal2D(RelNormal2D coord);
//	AbsNormal2D		ToAbsNormal2D(PixelCoord2D coord);
//	AbsNormal2D		ToAbsNormal2D(ScreenCoord2D coord);
//
//	RelNormal2D		ToRelNormal2D(AbsNormal2D coord);
//	RelNormal2D		ToRelNormal2D(RelNormal2D coord);
//	RelNormal2D		ToRelNormal2D(PixelCoord2D coord);
//	RelNormal2D		ToRelNormal2D(ScreenCoord2D coord);
//
//	PixelCoord2D	ToPixelCoord2D(AbsNormal2D coord);
//	PixelCoord2D	ToPixelCoord2D(RelNormal2D coord);
//	PixelCoord2D	ToPixelCoord2D(PixelCoord2D coord);
//	PixelCoord2D	ToPixelCoord2D(ScreenCoord2D coord);
//
//	ScreenCoord2D	ToScreenCoord2D(AbsNormal2D coord);
//	ScreenCoord2D	ToScreenCoord2D(RelNormal2D coord);
//	ScreenCoord2D	ToScreenCoord2D(PixelCoord2D coord);
//	ScreenCoord2D	ToScreenCoord2D(ScreenCoord2D coord);
};

#endif