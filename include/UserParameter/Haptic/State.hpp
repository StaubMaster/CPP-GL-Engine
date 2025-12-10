#ifndef  USER_PARAMETER_HAPTIC_STATE_HPP
# define USER_PARAMETER_HAPTIC_STATE_HPP

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
	void	Down();
	void	Up();
	void	Press();
	void	Release();

	bool	IsDown() const;
	bool	IsUp() const;
	bool	IsPress() const;
	bool	IsRelease() const;

	void	Tick();
};

};

};

#endif