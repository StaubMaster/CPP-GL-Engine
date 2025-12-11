#ifndef  USER_PARAMETER_HAPTIC_CODE_HPP
# define USER_PARAMETER_HAPTIC_CODE_HPP

//#include "OpenGL/openGL.h"

//	Rename to Token

namespace UserParameter
{

namespace Haptic
{

struct Code
{
	private:
	int Flags;

	public:
	Code();
	Code(int flags);

	public:
	bool	operator ==(int code) const;
};

};

};

#endif