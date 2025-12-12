#include "UserParameter/Haptic/State.hpp"
#include "OpenGL/openGL.h"

#define HAPTIC_STATE_BITS	0b111
#define HAPTIC_STATE_UD_BIT	0b001
#define HAPTIC_STATE_U_BIT	0b000
#define HAPTIC_STATE_D_BIT	0b001
#define HAPTIC_STATE_PR_BIT	0b110
#define HAPTIC_STATE_P_BIT	0b010
#define HAPTIC_STATE_R_BIT	0b100



UserParameter::Haptic::State::State() :
	Token(0), Flags(0)
{ }



void	UserParameter::Haptic::State::Tick()
{
	Flags = Flags & (~HAPTIC_STATE_PR_BIT);
}
void	UserParameter::Haptic::State::Update(Action action)
{
	if (action.IsPress())
	{
		Flags = (Flags & (~HAPTIC_STATE_PR_BIT)) | HAPTIC_STATE_P_BIT;
		Flags = (Flags & (~HAPTIC_STATE_UD_BIT)) | HAPTIC_STATE_D_BIT;
	}
	else if (action.IsRelease())
	{
		Flags = (Flags & (~HAPTIC_STATE_PR_BIT)) | HAPTIC_STATE_R_BIT;
		Flags = (Flags & (~HAPTIC_STATE_UD_BIT)) | HAPTIC_STATE_U_BIT;
	}
}



bool	UserParameter::Haptic::State::IsUp() const		{ return (Flags & HAPTIC_STATE_UD_BIT) == HAPTIC_STATE_U_BIT; }
bool	UserParameter::Haptic::State::IsDown() const	{ return (Flags & HAPTIC_STATE_UD_BIT) == HAPTIC_STATE_D_BIT; }
bool	UserParameter::Haptic::State::IsPress() const	{ return (Flags & HAPTIC_STATE_PR_BIT) == HAPTIC_STATE_P_BIT; }
bool	UserParameter::Haptic::State::IsRelease() const	{ return (Flags & HAPTIC_STATE_PR_BIT) == HAPTIC_STATE_R_BIT; }
