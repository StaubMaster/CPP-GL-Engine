#ifndef  USER_PARAMETER_KEY_HPP
# define USER_PARAMETER_KEY_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Modifier.hpp"

namespace UserParameter
{

struct Key
{
	Haptic::Code		Code;
	int					Scancode;
	Haptic::Action		Action;
	Haptic::Modifier	Mods;

	Key(int keycode, int scancode, int action, int mods);
};

};

#endif