#ifndef  USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP
# define USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/MouseDeclare.hpp"

# include "ValueType/Point2D.hpp"

# include "Function/Pointer.hpp"

class Window;

namespace UserParameter
{

namespace Mouse
{

class EventManager
{
	private:
	Window & window;
	public:
	UserParameter::Mouse::ButtonRange Buttons;

	public:
	FunctionPointer<UserParameter::Mouse::Click>	CallbackClick;
	FunctionPointer<UserParameter::Mouse::Scroll>	CallbackScroll;
	FunctionPointer<UserParameter::Mouse::Position>	CallbackMove;
	FunctionPointer<UserParameter::Mouse::Drag>		CallbackDrag;

	public:
	EventManager(Window & win);
	~EventManager();
	EventManager(const EventManager & other) = delete;
	EventManager & operator=(const EventManager & other) = delete;

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
};

};

};

#endif