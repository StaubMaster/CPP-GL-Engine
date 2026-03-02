#ifndef  USER_PARAMETER_MOUSE_DRAG_HPP
# define USER_PARAMETER_MOUSE_DRAG_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Drag
{
	Haptic::Code		Code;
	Haptic::Modifier	Mods;
	DisplayPosition		Origin;
	DisplayPosition		Position;
};

};

};

#endif