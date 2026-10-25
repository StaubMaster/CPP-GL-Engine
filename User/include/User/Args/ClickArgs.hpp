#ifndef  USER_ARGS_CLICK_HPP
# define USER_ARGS_CLICK_HPP

# include "User/Enums/MouseButtons.hpp"
# include "User/Enums/Action.hpp"
# include "User/Enums/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

struct ClickArgs
{
	::MouseButtons		Button;
	::Action			Action;
	::Modifier			Mods;

	DisplayPosition		Position;

	ClickArgs(::MouseButtons button, ::Action action, ::Modifier mods, DisplayPosition position);
};

#endif