#ifndef  USER_PARAMETER_KEYBOARD_KEY_DATA_HPP
# define USER_PARAMETER_KEYBOARD_KEY_DATA_HPP

# include "UserParameter/KeyBoard/Key/State.hpp"

namespace UserParameter
{

namespace KeyBoard
{

namespace Key
{

struct Data : public Key::State
{
	public:
	unsigned short Token;
};

};

};

};

#endif