#ifndef  USER_PARAMETER_KEYBOARD_RANGE_1_HPP
# define USER_PARAMETER_KEYBOARD_RANGE_1_HPP

# include "UserParameter/KeyBoard/Key/Data.hpp"

namespace UserParameter
{

namespace KeyBoard
{

struct KeyRange1
{
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	KeysCount;
	Key::Data *		Keys;

	KeyRange1();
	KeyRange1(unsigned short tokenMin, unsigned int tokenMax);
	~KeyRange1();

	KeyRange1(const KeyRange1 & other);
	KeyRange1 & operator =(const KeyRange1 & other);

	bool				Has(unsigned short token) const;
	Key::Data	&		operator [](unsigned short token);
	const Key::Data &	operator [](unsigned short token) const;

	void	Tick();
};

};

};

#endif