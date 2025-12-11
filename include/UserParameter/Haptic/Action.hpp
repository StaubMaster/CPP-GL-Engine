#ifndef  USER_PARAMETER_HAPTIC_ACTION_HPP
# define USER_PARAMETER_HAPTIC_ACTION_HPP

//#include "OpenGL/openGL.h"

namespace UserParameter
{

namespace Haptic
{

struct Action
{
	private:
	int Flags;

	public:
	Action();
	Action(int flags);

	public:
	bool	IsPress() const;		//GLFW_PRESS
	bool	IsRepeat() const;		//GLFW_REPEAT
	bool	IsRelease() const;		//GLFW_RELEASE
};

};

};

#endif