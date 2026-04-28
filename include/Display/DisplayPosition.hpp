#ifndef  DISPLAY_DISPLAY_POSITION_HPP
# define DISPLAY_DISPLAY_POSITION_HPP

# include "NormalPosition.hpp"
# include "PixelPosition.hpp"

# include "ValueType/Point2D.hpp"

struct DisplaySize;

// allways from Bottom Right
struct DisplayPosition
{
	NormalPosition	Normal;
	PixelPosition	Window;
	PixelPosition	Buffer;

	~DisplayPosition();
	DisplayPosition();

	DisplayPosition(const DisplayPosition & other);
	DisplayPosition & operator=(const DisplayPosition & other);

//	void ChangeWindowCorner(Point2D pos, DisplaySize size);
	void ChangeNormalRel(Point2D pos, DisplaySize size);

//	static DisplayPosition FromWindowCorner(Point2D pos, DisplaySize size);
	static DisplayPosition FromNormalRel(Point2D pos, DisplaySize size);
};

#endif