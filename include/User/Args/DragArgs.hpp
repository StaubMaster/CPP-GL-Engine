#ifndef  USER_ARGS_DRAG_HPP
# define USER_ARGS_DRAG_HPP

# include "User/Enums/MouseButtons.hpp"
# include "User/Enums/Action.hpp"
# include "User/Enums/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

struct DragArgs
{
	::Modifier			Mods;
	::Action			Action;
	::MouseButtons		Button;

	DisplayPosition		Origin;
	DisplayPosition		Position;
};

#endif