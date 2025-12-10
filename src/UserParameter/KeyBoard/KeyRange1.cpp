#include "UserParameter/KeyBoard/KeyRange1.hpp"



UserParameter::KeyBoard::KeyRange1::KeyRange1()
{
	TokenMin = 0;
	TokenMax = 0;
	KeysCount = 0;
	Keys = new Haptic::State[KeysCount];
}
UserParameter::KeyBoard::KeyRange1::KeyRange1(unsigned short tokenMin, unsigned int tokenMax)
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
UserParameter::KeyBoard::KeyRange1::~KeyRange1()
{
	delete[] Keys;
}



UserParameter::KeyBoard::KeyRange1::KeyRange1(const KeyRange1 & other)
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
UserParameter::KeyBoard::KeyRange1 & UserParameter::KeyBoard::KeyRange1::operator =(const KeyRange1 & other)
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



bool UserParameter::KeyBoard::KeyRange1::Has(unsigned short token) const
{
	return (token >= TokenMin && token <= TokenMax);
}
UserParameter::Haptic::State	& UserParameter::KeyBoard::KeyRange1::operator [](unsigned short token)
{
	return Keys[token - TokenMin];
}
const UserParameter::Haptic::State & UserParameter::KeyBoard::KeyRange1::operator [](unsigned short token) const
{
	return Keys[token - TokenMin];
}



void	UserParameter::KeyBoard::KeyRange1::Tick()
{
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i].Tick();
	}
}
