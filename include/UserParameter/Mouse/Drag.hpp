#ifndef  USER_PARAMETER_MOUSE_DRAG_HPP
# define USER_PARAMETER_MOUSE_DRAG_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Modifier.hpp"
# include "UserParameter/Mouse/Position.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Drag
{
	Haptic::Code		Code;
	Haptic::Modifier	Mods;
	Mouse::Position		Origin;
	Mouse::Position		Position;
};

};

};

#endif