#ifndef  USER_PARAMETER_MOUSE_BUTTONDATA_HPP
# define USER_PARAMETER_MOUSE_BUTTONDATA_HPP

# include "UserParameter/Haptic/State.hpp"
# include "UserParameter/Haptic/Action.hpp"

# include "Display/DisplayPosition.hpp"

/*	what stuff needs to be remembered per MouseButton
last Click time (for multiClick) ?
	not now
Drag Origin
*/

namespace UserParameter
{

namespace Mouse
{

struct ButtonData
{
	Haptic::State	State;
	//LastPressTime
	//LastReleaseTime
	DisplayPosition	LastPressPosition;
	DisplayPosition	LastReleasePosition;

	void	Update(DisplayPosition pos, Haptic::Action action);
};

};

};

#endif