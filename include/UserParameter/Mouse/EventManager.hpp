#ifndef  USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP
# define USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/MouseDeclare.hpp"

# include "ValueType/Point2D.hpp"

# include "Function/Pointer.hpp"

/*	instead of putting all the managing logic in the Window, put it here
*/



class Window;

namespace UserParameter
{

namespace Mouse
{

struct EventManager
{
	private:
	Window & window;
	public:
	UserParameter::Mouse::ButtonRange Buttons;

	private:
	FunctionPointer<UserParameter::Mouse::Click>	CallbackClick;
	FunctionPointer<UserParameter::Mouse::Scroll>	CallbackScroll;
	FunctionPointer<UserParameter::Mouse::Position>	CallbackMove;
	FunctionPointer<UserParameter::Mouse::Drag>		CallbackDrag;

	public:
	EventManager(Window & win);

	public:
	bool	CursorModeIsLocked() const;
	void	CursorModeLock();
	void	CursorModeFree();
	void	CursorModeToggle();

	Mouse::Position CursorPixelPosition() const;
	Mouse::Position CursorPixelCentered() const;

	public:
	void Tick();
	void UpdateClick(int button, int action, int mods);
	void UpdateScroll(float offset_x, float offset_y);
	void UpdateMove(double x_pos, double y_pos);

	public:
	void ChangeClick(BaseFunction<void, UserParameter::Mouse::Click> * func);
	void ChangeScroll(BaseFunction<void, UserParameter::Mouse::Scroll> * func);
	void ChangeMove(BaseFunction<void, UserParameter::Mouse::Position> * func);
	void ChangeDrag(BaseFunction<void, UserParameter::Mouse::Drag> * func);
};

};

};

#endif