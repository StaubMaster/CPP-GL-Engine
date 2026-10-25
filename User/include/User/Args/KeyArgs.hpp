#ifndef  USER_ARGS_KEY_HPP
# define USER_ARGS_KEY_HPP

# include "User/Enums/Keys.hpp"
# include "User/Enums/Action.hpp"
# include "User/Enums/Modifier.hpp"

struct KeyArgs
{
	::Keys		Key;
	int			Scancode;
	::Action	Action;
	::Modifier	Mods;

	KeyArgs(::Keys keycode, int scancode, ::Action action, ::Modifier mods);
};

#endif