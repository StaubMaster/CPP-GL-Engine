#include "User/Args/ClickArgs.hpp"



ClickArgs::ClickArgs(::MouseButtons button, ::Action action, ::Modifier mods, DisplayPosition position)
	: Button(button)
	, Action(action)
	, Mods(mods)
	, Position(position)
{ }
