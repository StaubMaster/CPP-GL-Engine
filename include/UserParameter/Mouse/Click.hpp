#ifndef  USER_PARAMETER_MOUSE_CLICK_HPP
# define USER_PARAMETER_MOUSE_CLICK_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

# include "UserParameter/Mouse/Position.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Click
{
	Haptic::Code		Code;
	Haptic::Action		Action;
	Haptic::Modifier	Mods;
	Mouse::Position		Position;
};

};

};

#endif