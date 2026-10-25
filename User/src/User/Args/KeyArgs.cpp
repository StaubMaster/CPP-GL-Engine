#include "User/Args/KeyArgs.hpp"



KeyArgs::KeyArgs(::Keys keycode, int scancode, ::Action action, ::Modifier mods)
	: Key(keycode)
	, Scancode(scancode)
	, Action(action)
	, Mods(mods)
{ }
