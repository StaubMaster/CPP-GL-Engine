#ifndef  USER_PARAMETER_MOUSE_CLICK_HPP
# define USER_PARAMETER_MOUSE_CLICK_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Click
{
	Haptic::Code		Code;
	Haptic::Action		Action;
	Haptic::Modifier	Mods;
	DisplayPosition		Position;

	//public:
	//Click();
};

};

};

#endif