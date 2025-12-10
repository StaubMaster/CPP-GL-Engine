#ifndef  USER_PARAMETER_MOUSE_BUTTONRANGE_HPP
# define USER_PARAMETER_MOUSE_BUTTONRANGE_HPP

# include "UserParameter/Mouse/Button/Data.hpp"

namespace UserParameter
{

namespace Mouse
{

struct ButtonRange
{
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	KeysCount;
	Button::Data *		Keys;

	ButtonRange();
	ButtonRange(unsigned short tokenMin, unsigned int tokenMax);
	~ButtonRange();

	ButtonRange(const ButtonRange & other);
	ButtonRange & operator =(const ButtonRange & other);

	bool					Has(unsigned short token) const;
	Button::Data	&		operator [](unsigned short token);
	const Button::Data &	operator [](unsigned short token) const;

	void	Tick();
};

};

};

#endif