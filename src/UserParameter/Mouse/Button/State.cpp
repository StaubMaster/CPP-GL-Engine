#include "UserParameter/Mouse/Button/State.hpp"

#define BUTTONSTATE_BITS	0b111
#define BUTTONSTATE_UD_BIT	0b001
#define BUTTONSTATE_U_BIT	0b000
#define BUTTONSTATE_D_BIT	0b001
#define BUTTONSTATE_PR_BIT	0b110
#define BUTTONSTATE_P_BIT	0b010
#define BUTTONSTATE_R_BIT	0b100



void	UserParameter::Mouse::Button::State::Press()
{
	Data = (Data & (~BUTTONSTATE_PR_BIT)) | BUTTONSTATE_P_BIT;
	Data = (Data & (~BUTTONSTATE_UD_BIT)) | BUTTONSTATE_D_BIT;
}
void	UserParameter::Mouse::Button::State::Release()
{
	Data = (Data & (~BUTTONSTATE_PR_BIT)) | BUTTONSTATE_R_BIT;
	Data = (Data & (~BUTTONSTATE_UD_BIT)) | BUTTONSTATE_U_BIT;
}



bool	UserParameter::Mouse::Button::State::IsDown() const		{ return (Data & BUTTONSTATE_UD_BIT) == BUTTONSTATE_D_BIT; }
bool	UserParameter::Mouse::Button::State::IsUp() const		{ return (Data & BUTTONSTATE_UD_BIT) == BUTTONSTATE_U_BIT; }
bool	UserParameter::Mouse::Button::State::IsPress() const	{ return (Data & BUTTONSTATE_PR_BIT) == BUTTONSTATE_P_BIT; }
bool	UserParameter::Mouse::Button::State::IsRelease() const	{ return (Data & BUTTONSTATE_PR_BIT) == BUTTONSTATE_R_BIT; }



void	UserParameter::Mouse::Button::State::Tick()
{
	Data = Data & (~BUTTONSTATE_PR_BIT);
}
