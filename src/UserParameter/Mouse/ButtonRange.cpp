#include "UserParameter/Mouse/ButtonRange.hpp"



UserParameter::Mouse::ButtonRange::ButtonRange()
{
	TokenMin = 0;
	TokenMax = 0;
	KeysCount = 0;
	Keys = new Haptic::State[KeysCount];
}
UserParameter::Mouse::ButtonRange::ButtonRange(unsigned short tokenMin, unsigned int tokenMax)
{
	TokenMin = tokenMin;
	TokenMax = tokenMax;
	KeysCount = (TokenMax - TokenMin) + 1;
	Keys = new Haptic::State[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i].Token = i + TokenMin;
	}
}
UserParameter::Mouse::ButtonRange::~ButtonRange()
{
	delete[] Keys;
}



UserParameter::Mouse::ButtonRange::ButtonRange(const ButtonRange & other)
{
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	KeysCount= other.KeysCount;
	Keys = new Haptic::State[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i] = other.Keys[i];
	}
}
UserParameter::Mouse::ButtonRange & UserParameter::Mouse::ButtonRange::operator =(const ButtonRange & other)
{
	delete[] Keys;
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	KeysCount= other.KeysCount;
	Keys = new Haptic::State[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i] = other.Keys[i];
	}
	return *this;
}



bool UserParameter::Mouse::ButtonRange::Has(unsigned short token) const
{
	return (token >= TokenMin && token <= TokenMax);
}
UserParameter::Haptic::State	& UserParameter::Mouse::ButtonRange::operator [](unsigned short token)
{
	return Keys[token - TokenMin];
}
const UserParameter::Haptic::State & UserParameter::Mouse::ButtonRange::operator [](unsigned short token) const
{
	return Keys[token - TokenMin];
}



void	UserParameter::Mouse::ButtonRange::Tick()
{
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i].Tick();
	}
}
