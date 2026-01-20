#ifndef  USER_PARAMETER_MOUSE_BUTTONDATA_HPP
# define USER_PARAMETER_MOUSE_BUTTONDATA_HPP

# include "UserParameter/Mouse/Position.hpp"
# include "UserParameter/Haptic/State.hpp"
# include "UserParameter/Haptic/Action.hpp"

# include "ValueType/Point2D.hpp"

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
	Mouse::Position	LastPressPosition;
	Mouse::Position	LastReleasePosition;

	void	Update(Mouse::Position pos, Haptic::Action action);
};

};

};

#endif