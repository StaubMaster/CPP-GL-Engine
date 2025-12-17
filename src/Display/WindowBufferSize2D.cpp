#include "Display/WindowBufferSize2D.hpp"
#include "Display/SizeRatio2D.hpp"
#include "Display/AbsNormal2D.hpp"
#include "Display/RelNormal2D.hpp"
#include "Display/PixelCoord2D.hpp"
#include "Display/ScreenCoord2D.hpp"



void WindowBufferSize2D::Change(Point2D winSize, Point2D bufSize)
{
	WindowSize = winSize;
	BufferSize = bufSize;
	Ratio = SizeRatio2D::NormalRatio(WindowSize);
}



AbsNormal2D WindowBufferSize2D::ToAbsNormal2D(AbsNormal2D coords) { return coords; }
AbsNormal2D WindowBufferSize2D::ToAbsNormal2D(RelNormal2D coords) { return (coords + 1) / 2; }
AbsNormal2D WindowBufferSize2D::ToAbsNormal2D(PixelCoord2D coords) { return coords / WindowSize; }
AbsNormal2D WindowBufferSize2D::ToAbsNormal2D(ScreenCoord2D coords) { return coords / BufferSize; }



RelNormal2D WindowBufferSize2D::ToRelNormal2D(AbsNormal2D coords) { return (coords * 2) - 1; }
RelNormal2D WindowBufferSize2D::ToRelNormal2D(RelNormal2D coords) { return coords; }
RelNormal2D WindowBufferSize2D::ToRelNormal2D(PixelCoord2D coords) { return ToRelNormal2D(ToAbsNormal2D(coords)); }
RelNormal2D WindowBufferSize2D::ToRelNormal2D(ScreenCoord2D coords) { return ToRelNormal2D(ToAbsNormal2D(coords)); }



PixelCoord2D WindowBufferSize2D::ToPixelCoord2D(AbsNormal2D coords) { return coords * WindowSize; }
PixelCoord2D WindowBufferSize2D::ToPixelCoord2D(RelNormal2D coords) { return ToPixelCoord2D(ToAbsNormal2D(coords)); }
PixelCoord2D WindowBufferSize2D::ToPixelCoord2D(PixelCoord2D coords) { return coords; }
PixelCoord2D WindowBufferSize2D::ToPixelCoord2D(ScreenCoord2D coords) { return ToPixelCoord2D(ToAbsNormal2D(coords)); }



ScreenCoord2D WindowBufferSize2D::ToScreenCoord2D(AbsNormal2D coords) { return coords * BufferSize; }
ScreenCoord2D WindowBufferSize2D::ToScreenCoord2D(RelNormal2D coords) { return ToScreenCoord2D(ToAbsNormal2D(coords)); }
ScreenCoord2D WindowBufferSize2D::ToScreenCoord2D(PixelCoord2D coords) { return ToScreenCoord2D(ToAbsNormal2D(coords)); }
ScreenCoord2D WindowBufferSize2D::ToScreenCoord2D(ScreenCoord2D coords) { return coords; }
