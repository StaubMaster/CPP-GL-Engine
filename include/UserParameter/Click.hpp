#ifndef  USER_PARAMETER_CLICK_HPP
# define USER_PARAMETER_CLICK_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

# include "DataStruct/Point2D.hpp"

namespace UserParameter
{

struct Click
{
	Haptic::Code		Code;
	Haptic::Action		Action;
	Haptic::Modifier	Mods;
	Point2D Position;

	Click(int code, int action, int mods, Point2D pos);
};

};

#endif