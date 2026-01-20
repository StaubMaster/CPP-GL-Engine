#ifndef  USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP
# define USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/MouseDeclare.hpp"

# include "ValueType/Point2D.hpp"

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
	void (*CallbackClick)	(UserParameter::Mouse::Click);
	void (*CallbackScroll)	(UserParameter::Mouse::Scroll);
	void (*CallbackMove)	(UserParameter::Mouse::Position);
	void (*CallbackDrag)	(UserParameter::Mouse::Drag);

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
	void ChangeCallbackClick(void (*func)(UserParameter::Mouse::Click));
	void ChangeCallbackScroll(void (*func)(UserParameter::Mouse::Scroll));
	void ChangeCallbackMove(void (*func)(UserParameter::Mouse::Position));
	void ChangeCallbackDrag(void (*func)(UserParameter::Mouse::Drag));

	//	rename to Invoke ?
	private:
	void RelayCallbackClick(UserParameter::Mouse::Click params);
	void RelayCallbackScroll(UserParameter::Mouse::Scroll params);
	void RelayCallbackMove(UserParameter::Mouse::Position params);
	void RelayCallbackDrag(UserParameter::Mouse::Drag params);
};

};

};

#endif