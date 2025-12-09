#include "UserParameter/Haptic/Action.hpp"
#include "OpenGL/openGL.h"



UserParameter::Haptic::Action::Action(int flags) :
	Flags(flags)
{ }



bool UserParameter::Haptic::Action::IsPress() const		{ return (Flags & GLFW_PRESS) != 0; }
bool UserParameter::Haptic::Action::IsRepeat() const	{ return (Flags & GLFW_REPEAT) != 0; }
bool UserParameter::Haptic::Action::IsRelease() const	{ return (Flags & GLFW_RELEASE) != 0; }
