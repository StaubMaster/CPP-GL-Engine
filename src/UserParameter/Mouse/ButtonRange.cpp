#include "UserParameter/Mouse/ButtonRange.hpp"



UserParameter::Mouse::ButtonRange::ButtonRange()
{
	TokenMin = 0;
	TokenMax = 0;
	ButtonsCount = 0;
	Buttons = new ButtonData[ButtonsCount];
}
UserParameter::Mouse::ButtonRange::ButtonRange(unsigned short tokenMin, unsigned short tokenMax)
{
	TokenMin = tokenMin;
	TokenMax = tokenMax;
	ButtonsCount = (TokenMax - TokenMin) + 1;
	Buttons = new ButtonData[ButtonsCount];
	for (unsigned int i = 0; i < ButtonsCount; i++)
	{
		Buttons[i].State.Token = i + TokenMin;
	}
}
UserParameter::Mouse::ButtonRange::~ButtonRange()
{
	delete[] Buttons;
}



UserParameter::Mouse::ButtonRange::ButtonRange(const ButtonRange & other)
{
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	ButtonsCount= other.ButtonsCount;
	Buttons = new ButtonData[ButtonsCount];
	for (unsigned int i = 0; i < ButtonsCount; i++)
	{
		Buttons[i] = other.Buttons[i];
	}
}
UserParameter::Mouse::ButtonRange & UserParameter::Mouse::ButtonRange::operator =(const ButtonRange & other)
{
	delete[] Buttons;
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	ButtonsCount= other.ButtonsCount;
	Buttons = new ButtonData[ButtonsCount];
	for (unsigned int i = 0; i < ButtonsCount; i++)
	{
		Buttons[i] = other.Buttons[i];
	}
	return *this;
}



UserParameter::Mouse::ButtonData	& UserParameter::Mouse::ButtonRange::operator [](unsigned short token)
{
	return Buttons[token - TokenMin];
}
const UserParameter::Mouse::ButtonData & UserParameter::Mouse::ButtonRange::operator [](unsigned short token) const
{
	return Buttons[token - TokenMin];
}



bool UserParameter::Mouse::ButtonRange::Has(unsigned short token) const
{
	return (token >= TokenMin && token <= TokenMax);
}
bool UserParameter::Mouse::ButtonRange::IsUp(unsigned short token) const
{
	if (!Has(token)) { return false; }
	return (*this)[token].State.IsUp();
}
bool UserParameter::Mouse::ButtonRange::IsDown(unsigned short token) const
{
	if (!Has(token)) { return false; }
	return (*this)[token].State.IsDown();
}
bool UserParameter::Mouse::ButtonRange::IsPress(unsigned short token) const
{
	if (!Has(token)) { return false; }
	return (*this)[token].State.IsPress();
}
bool UserParameter::Mouse::ButtonRange::IsRelease(unsigned short token) const
{
	if (!Has(token)) { return false; }
	return (*this)[token].State.IsRelease();
}



void	UserParameter::Mouse::ButtonRange::Update(Mouse::Position pos, Haptic::Code code, Haptic::Action action)
{
	if (Has(code.Flags))
	{
		UserParameter::Mouse::ButtonData & data = Buttons[code.Flags];
		data.Update(pos, action);
	}
}
void	UserParameter::Mouse::ButtonRange::Tick()
{
	for (unsigned int i = 0; i < ButtonsCount; i++)
	{
		Buttons[i].State.Tick();
	}
}
