#ifndef  DISPLAY_WINDOWBUFFERSIZE2D_HPP
# define DISPLAY_WINDOWBUFFERSIZE2D_HPP

# include "DataStruct/Point2D.hpp"

struct AbsNormal2D;
struct RelNormal2D;
struct PixelCoord2D;
struct ScreenCoord2D;

/*
AbsNormal		[ 0 ; 1 ]
RelNormal		[ -1 ; +1 ]
PixelCoords		[ 0 ; FrameBufferSize ]
ScreenCoords	[ 0 ; WindowSize ]
*/

struct WindowBufferSize2D
{
	Point2D	WindowSize;
	Point2D	BufferSize;	//	FrameBuffer
	//Point2D	Scale;		//	Window vs Buffer
	Point2D	Ratio;		//	W vs H

	void Change(Point2D winSize, Point2D bufSize);

	AbsNormal2D		ToAbsNormal2D(AbsNormal2D coord);
	AbsNormal2D		ToAbsNormal2D(RelNormal2D coord);
	AbsNormal2D		ToAbsNormal2D(PixelCoord2D coord);
	AbsNormal2D		ToAbsNormal2D(ScreenCoord2D coord);

	RelNormal2D		ToRelNormal2D(AbsNormal2D coord);
	RelNormal2D		ToRelNormal2D(RelNormal2D coord);
	RelNormal2D		ToRelNormal2D(PixelCoord2D coord);
	RelNormal2D		ToRelNormal2D(ScreenCoord2D coord);

	PixelCoord2D	ToPixelCoord2D(AbsNormal2D coord);
	PixelCoord2D	ToPixelCoord2D(RelNormal2D coord);
	PixelCoord2D	ToPixelCoord2D(PixelCoord2D coord);
	PixelCoord2D	ToPixelCoord2D(ScreenCoord2D coord);

	ScreenCoord2D	ToScreenCoord2D(AbsNormal2D coord);
	ScreenCoord2D	ToScreenCoord2D(RelNormal2D coord);
	ScreenCoord2D	ToScreenCoord2D(PixelCoord2D coord);
	ScreenCoord2D	ToScreenCoord2D(ScreenCoord2D coord);

	//	TL <==> BL
};

#endif