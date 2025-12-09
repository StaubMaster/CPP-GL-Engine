#ifndef  USER_PARAMETER_HAPTIC_MODIFIER_HPP
# define USER_PARAMETER_HAPTIC_MODIFIER_HPP

//#include "OpenGL/openGL.h"

namespace UserParameter
{

namespace Haptic
{

struct Modifier
{
	private:
	int Flags;

	public:
	Modifier(int flags);

	public:
	bool	IsShift() const;		//GLFW_MOD_SHIFT		0x0001
	bool	IsControl() const;		//GLFW_MOD_CONTROL		0x0002
	bool	IsAlt() const;			//GLFW_MOD_ALT			0x0008

	bool	IsSuper() const;		//GLFW_MOD_SUPER		0x0008

	bool	IsCapsLock() const;		//GLFW_MOD_CAPS_LOCK	0x0010
	bool	IsNumLock() const;		//GLFW_MOD_NUM_LOCK		0x0020
	bool	IsScrollLock() const;	//GLFW_KEY_SCROLL_LOCK
};

};

};

#endif