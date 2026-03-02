#ifndef  USER_PARAMETER_MOUSE_SCROLL_HPP
# define USER_PARAMETER_MOUSE_SCROLL_HPP

# include "UserParameter/Haptic/Modifier.hpp"

# include "Display/DisplayPosition.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Scroll
{
	float				X;
	float				Y;
	Haptic::Modifier	Mods;
	DisplayPosition		Position;

	//public:
	//Scroll();
};

};

};

#endif