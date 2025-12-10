#include "UserParameter/Cursor.hpp"



UserParameter::Cursor::Cursor(Point2D orig, Point2D pos, int change, bool dragging) :
	Origin(orig),
	Position(pos),
	Change(change),
	Dragging(dragging)
{ }



bool UserParameter::Cursor::IsMove()	{ return (Change == CURSOR_CHANGE_MOVE); }
bool UserParameter::Cursor::IsEnter()	{ return (Change == CURSOR_CHANGE_ENTER); }
bool UserParameter::Cursor::IsLeave()	{ return (Change == CURSOR_CHANGE_LEAVE); }

bool UserParameter::Cursor::IsDragging()	{ return (Dragging); }
