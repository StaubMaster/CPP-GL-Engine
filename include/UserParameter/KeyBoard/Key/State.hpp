#ifndef  USER_PARAMETER_KEYBOARD_KEY_STATE_HPP
# define USER_PARAMETER_KEYBOARD_KEY_STATE_HPP

namespace UserParameter
{

namespace KeyBoard
{

namespace Key
{
	
struct State
{
	private:
	unsigned int Data;

	public:
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

};

#endif