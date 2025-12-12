#ifndef  USER_PARAMETER_HAPTIC_STATE_HPP
# define USER_PARAMETER_HAPTIC_STATE_HPP

# include "UserParameter/Haptic/Code.hpp"
# include "UserParameter/Haptic/Action.hpp"

namespace UserParameter
{

namespace Haptic
{

struct State
{
	public:
	unsigned short Token;
	private:
	unsigned char Flags;

	public:
	State();

	public:
	void	Tick();
	void	Update(Action action);

	bool	IsUp() const;
	bool	IsDown() const;
	bool	IsPress() const;
	bool	IsRelease() const;
};

};

};

#endif