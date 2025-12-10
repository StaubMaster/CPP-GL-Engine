#ifndef  USER_PARAMETER_MOUSE_BUTTONRANGE_HPP
# define USER_PARAMETER_MOUSE_BUTTONRANGE_HPP

# include "UserParameter/Haptic/State.hpp"



namespace UserParameter
{

namespace Mouse
{

struct ButtonRange
{
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	KeysCount;
	Haptic::State *		Keys;

	ButtonRange();
	ButtonRange(unsigned short tokenMin, unsigned int tokenMax);
	~ButtonRange();

	ButtonRange(const ButtonRange & other);
	ButtonRange & operator =(const ButtonRange & other);

	bool					Has(unsigned short token) const;
	Haptic::State	&		operator [](unsigned short token);
	const Haptic::State &	operator [](unsigned short token) const;

	void	Tick();
};

};

};

#endif