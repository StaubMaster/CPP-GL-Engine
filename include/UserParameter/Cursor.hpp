#ifndef  USER_PARAMETER_CURSOR_HPP
# define USER_PARAMETER_CURSOR_HPP

# include "DataStruct/Point2D.hpp"

/*	for when Cursor moved
maybe also Enter / Leave
also just Move in general

current mouse button states ?

Origin ?
so for Dragging
note where Drag began ?

have seperate Drags for different MouseButtons ?

remember Frame when Drag began ?
*/

# define CURSOR_CHANGE_MOVE  0b00
# define CURSOR_CHANGE_ENTER 0b01
# define CURSOR_CHANGE_LEAVE 0b10

namespace UserParameter
{

struct Cursor
{
	public:
	Point2D Origin;
	Point2D Position;

	private:
	int		Change;
	bool	Dragging;

	public:
	Cursor(Point2D orig, Point2D pos, int change, bool dragging);

	public:
	bool	IsMove();
	bool	IsEnter();
	bool	IsLeave();

	bool	IsDragging();
};

};

#endif