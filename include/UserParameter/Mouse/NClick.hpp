#ifndef  USER_PARAMETER_MOUSE_N_CLICK_HPP
# define USER_PARAMETER_MOUSE_N_CLICK_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

# include "UserParameter/Mouse/Position.hpp"

namespace UserParameter
{

namespace Mouse
{

struct NClick
{
	Haptic::Code		Code;
	Haptic::Modifier	Mods;

	Mouse::Position		Position;
};

};

};

#endif