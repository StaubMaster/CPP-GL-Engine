#ifndef  USER_PARAMETER_MOUSE_BUTTON_DATA_HPP
# define USER_PARAMETER_MOUSE_BUTTON_DATA_HPP

# include "UserParameter/Mouse/Button/State.hpp"

namespace UserParameter
{

namespace Mouse
{
	
namespace Button
{

struct Data : public Button::State
{
	unsigned short	Token;
};

};

};

};

#endif