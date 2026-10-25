#ifndef  USER_ARGS_DRAG_HPP
# define USER_ARGS_DRAG_HPP

# include "User/Enums/MouseButtons.hpp"
# include "User/Enums/Action.hpp"
# include "User/Enums/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

struct DragArgs
{
	::MouseButtons		Button;
	/* Action does not refer to MouseButton
		Press: start of Drag
		Repeat: Drag movement
		Release: end of Drag
	*/
	::Action			Action;
	::Modifier			Mods;

	DisplayPosition		Position;

	DragArgs(::MouseButtons button, ::Action action, ::Modifier mods, DisplayPosition pos);
};

#endif