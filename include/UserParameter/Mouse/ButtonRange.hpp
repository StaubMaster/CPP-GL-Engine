#ifndef  USER_PARAMETER_MOUSE_BUTTONRANGE_HPP
# define USER_PARAMETER_MOUSE_BUTTONRANGE_HPP

# include "UserParameter/Mouse/ButtonData.hpp"
# include "UserParameter/Haptic/Action.hpp"
# include "UserParameter/Haptic/Code.hpp"

# include "Display/DisplayPosition.hpp"



namespace UserParameter
{

namespace Mouse
{

/*	Inherit from Base
make a struct for Index to differentiate form tokens ?
make Containers for multidimensional stuff
*/
struct ButtonRange
{
	private:
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	public:
	unsigned short	ButtonsCount;
	private:
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

	void	Update(DisplayPosition pos, Haptic::Code code, Haptic::Action action);
	void	Tick();
};

};

};

#endif