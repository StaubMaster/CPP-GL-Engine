#include "UserParameter/KeyBoard/KeyRange2.hpp"



UserParameter::KeyBoard::KeyRange2::KeyRange2(unsigned int count)
{
	KeyArraysCount = count;
	KeyArrays = new KeyRange1[KeyArraysCount];
}
UserParameter::KeyBoard::KeyRange2::~KeyRange2()
{
	delete[] KeyArrays;
}



bool UserParameter::KeyBoard::KeyRange2::Has(unsigned short token) const
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return true;
		}
	}
	return false;
}
UserParameter::KeyBoard::Key::Data & UserParameter::KeyBoard::KeyRange2::operator [](unsigned short token)
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return KeyArrays[i][token];
		}
	}
	throw "Key Token not in Array";
}
const UserParameter::KeyBoard::Key::Data & UserParameter::KeyBoard::KeyRange2::operator [](unsigned short token) const
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return KeyArrays[i][token];
		}
	}
	throw "Key Token not in Array";
}



void	UserParameter::KeyBoard::KeyRange2::Tick()
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		KeyArrays[i].Tick();
	}
}
