#ifndef  USER_PARAMETER_KEY_HPP
# define USER_PARAMETER_KEY_HPP

namespace UserParameter
{

struct Key
{
	int KeyCode;
	int Scancode;
	int Action;
	int Mods;

	Key(int keycode, int scancode, int action, int mods);
};

};

#endif