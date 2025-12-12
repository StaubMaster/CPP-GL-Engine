#ifndef  USER_PARAMETER_MOUSE_BUTTONRANGE_HPP
# define USER_PARAMETER_MOUSE_BUTTONRANGE_HPP

# include "UserParameter/Mouse/ButtonData.hpp"
# include "UserParameter/Mouse/Position.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Code.hpp"



namespace UserParameter
{

namespace Mouse
{

struct ButtonRange
{
	private:
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	ButtonsCount;
	ButtonData *	Buttons;

	public:
	ButtonRange();
	ButtonRange(unsigned short tokenMin, unsigned short tokenMax);
	~ButtonRange();

	ButtonRange(const ButtonRange & other);
	ButtonRange & operator =(const ButtonRange & other);

	ButtonData & operator[](unsigned short token);
	const ButtonData & operator[](unsigned short token) const;

	bool	Has(unsigned short token) const;
	bool	IsUp(unsigned short token) const;
	bool	IsDown(unsigned short token) const;
	bool	IsPress(unsigned short token) const;
	bool	IsRelease(unsigned short token) const;

	void	Update(Mouse::Position pos, Haptic::Code code, Haptic::Action action);
	void	Tick();
};

};

};

#endif