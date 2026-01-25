#include "UserParameter/Haptic/Action.hpp"
#include <GLFW/glfw3.h>



UserParameter::Haptic::Action::Action() :
	Flags(0)
{ }
UserParameter::Haptic::Action::Action(int flags) :
	Flags(flags)
{ }



bool UserParameter::Haptic::Action::IsPress() const		{ return (Flags == GLFW_PRESS); }
bool UserParameter::Haptic::Action::IsRepeat() const	{ return (Flags == GLFW_REPEAT); }
bool UserParameter::Haptic::Action::IsRelease() const	{ return (Flags == GLFW_RELEASE); }
