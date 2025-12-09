#include "UserParameter/Key.hpp"



UserParameter::Key::Key(int keycode, int scancode, int action, int mods) :
	Code(keycode),
	Scancode(scancode),
	Action(action),
	Mods(mods)
{ }
