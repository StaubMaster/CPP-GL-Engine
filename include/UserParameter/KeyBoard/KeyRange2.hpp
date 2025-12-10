#ifndef  USER_PARAMETER_KEYBOARD_KEYRANGE2_HPP
# define USER_PARAMETER_KEYBOARD_KEYRANGE2_HPP

# include "UserParameter/KeyBoard/KeyRange1.hpp"

namespace UserParameter
{

namespace KeyBoard
{

struct KeyRange2
{
	unsigned int KeyArraysCount;
	KeyRange1 * KeyArrays;

	KeyRange2(unsigned int count);
	~KeyRange2();

	bool					Has(unsigned short token) const;
	Haptic::State &			operator [](unsigned short token);
	const Haptic::State &	operator [](unsigned short token) const;

	void	Tick();
};

};

};

#endif