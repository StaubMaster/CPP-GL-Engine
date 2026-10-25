#include "User/Args/DragArgs.hpp"



DragArgs::DragArgs(::MouseButtons button, ::Action action, ::Modifier mods, DisplayPosition pos)
	: Button(button)
	, Action(action)
	, Mods(mods)
	, Position(pos)
{ }
