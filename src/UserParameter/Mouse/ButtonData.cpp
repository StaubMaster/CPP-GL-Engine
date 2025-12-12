#include "UserParameter/Mouse/ButtonData.hpp"



void UserParameter::Mouse::ButtonData::Update(Mouse::Position pos, Haptic::Action action)
{
	if (action.IsPress())
	{
		LastPressPosition = pos;
	}
	else if (action.IsRelease())
	{
		LastReleasePosition = pos;
	}
	State.Update(action);
}
