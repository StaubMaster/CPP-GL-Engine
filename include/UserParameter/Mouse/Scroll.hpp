#ifndef  USER_PARAMETER_MOUSE_SCROLL_HPP
# define USER_PARAMETER_MOUSE_SCROLL_HPP

# include "UserParameter/Haptic/Modifier.hpp"
# include "UserParameter/Mouse/Position.hpp"

# include "ValueType/Point2D.hpp"

namespace UserParameter
{

namespace Mouse
{

struct Scroll
{
	float				X;
	float				Y;
	Haptic::Modifier	Mods;
	Mouse::Position		Position;

	//public:
	//Scroll();
};

};

};

#endif