#include "UserParameter/Haptic/Modifier.hpp"
#include "OpenGL/openGL.h"



UserParameter::Haptic::Modifier::Modifier() :
	Flags(0)
{ }
UserParameter::Haptic::Modifier::Modifier(int flags) :
	Flags(flags)
{ }



bool UserParameter::Haptic::Modifier::IsShift() const	{ return (Flags & GLFW_MOD_SHIFT) != 0; }
bool UserParameter::Haptic::Modifier::IsControl() const	{ return (Flags & GLFW_MOD_CONTROL) != 0; }
bool UserParameter::Haptic::Modifier::IsAlt() const		{ return (Flags & GLFW_MOD_ALT) != 0; }

bool UserParameter::Haptic::Modifier::IsSuper() const	{ return (Flags & GLFW_MOD_SUPER) != 0; }

bool UserParameter::Haptic::Modifier::IsCapsLock() const	{ return (Flags & GLFW_MOD_CAPS_LOCK) != 0; }
bool UserParameter::Haptic::Modifier::IsNumLock() const		{ return (Flags & GLFW_MOD_NUM_LOCK) != 0; }
bool UserParameter::Haptic::Modifier::IsScrollLock() const	{ return (Flags & GLFW_KEY_SCROLL_LOCK) != 0; }
