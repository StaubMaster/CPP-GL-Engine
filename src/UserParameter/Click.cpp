#include "UserParameter/Click.hpp"



UserParameter::Click::Click(int code, int action, int mods, Point2D pos) :
	Code(code),
	Action(action),
	Mods(mods),
	Position(pos)
{ }
