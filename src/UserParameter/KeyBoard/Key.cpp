#include "UserParameter/KeyBoard/Key.hpp"



UserParameter::KeyBoard::Key::Key(int keycode, int scancode, int action, int mods) :
	Code(keycode),
	Scancode(scancode),
	Action(action),
	Mods(mods)
{ }
