#ifndef  USER_PARAMETER_KEYBOARD_KEYRANGE1_HPP
# define USER_PARAMETER_KEYBOARD_KEYRANGE1_HPP

# include "UserParameter/Haptic/State.hpp"



namespace UserParameter
{

namespace KeyBoard
{

struct KeyRange1
{
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	KeysCount;
	Haptic::State *		Keys;

	KeyRange1();
	KeyRange1(unsigned short tokenMin, unsigned int tokenMax);
	~KeyRange1();

	KeyRange1(const KeyRange1 & other);
	KeyRange1 & operator =(const KeyRange1 & other);

	bool					Has(unsigned short token) const;
	Haptic::State	&		operator [](unsigned short token);
	const Haptic::State &	operator [](unsigned short token) const;

	void	Tick();
};

};

};

#endif