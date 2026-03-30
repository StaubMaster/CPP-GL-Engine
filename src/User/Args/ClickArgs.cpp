#include "User/Args/ClickArgs.hpp"

ClickArgs::ClickArgs(::Modifier mods, ::Action action, ::MouseButtons button, DisplayPosition position)
	: Mods(mods)
	, Action(action)
	, Button(button)
	, Position(position)
{ }
