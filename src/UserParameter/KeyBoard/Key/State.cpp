#include "UserParameter/KeyBoard/Key/State.hpp"

#define KEYSTATE_BITS	0b111
#define KEYSTATE_UD_BIT	0b001
#define KEYSTATE_U_BIT	0b000
#define KEYSTATE_D_BIT	0b001
#define KEYSTATE_PR_BIT	0b110
#define KEYSTATE_P_BIT	0b010
#define KEYSTATE_R_BIT	0b100



void	UserParameter::KeyBoard::Key::State::Press()
{
	Data = (Data & (~KEYSTATE_PR_BIT)) | KEYSTATE_P_BIT;
	Data = (Data & (~KEYSTATE_UD_BIT)) | KEYSTATE_D_BIT;
}
void	UserParameter::KeyBoard::Key::State::Release()
{
	Data = (Data & (~KEYSTATE_PR_BIT)) | KEYSTATE_R_BIT;
	Data = (Data & (~KEYSTATE_UD_BIT)) | KEYSTATE_U_BIT;
}



bool	UserParameter::KeyBoard::Key::State::IsDown() const		{ return (Data & KEYSTATE_UD_BIT) == KEYSTATE_D_BIT; }
bool	UserParameter::KeyBoard::Key::State::IsUp() const		{ return (Data & KEYSTATE_UD_BIT) == KEYSTATE_U_BIT; }
bool	UserParameter::KeyBoard::Key::State::IsPress() const	{ return (Data & KEYSTATE_PR_BIT) == KEYSTATE_P_BIT; }
bool	UserParameter::KeyBoard::Key::State::IsRelease() const	{ return (Data & KEYSTATE_PR_BIT) == KEYSTATE_R_BIT; }



void	UserParameter::KeyBoard::Key::State::Tick()
{
	Data = Data & (~KEYSTATE_PR_BIT);
}
