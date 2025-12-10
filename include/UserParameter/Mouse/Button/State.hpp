#ifndef  USER_PARAMETER_MOUSE_BUTTON_STATE_HPP
# define USER_PARAMETER_MOUSE_BUTTON_STATE_HPP

namespace UserParameter
{

namespace Mouse
{
	
namespace Button
{

struct State
{
	private:
	unsigned char Data;

	public:
	void	MakeDown();
	void	MakeUp();
	void	MakePress();
	void	MakeRelease();

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