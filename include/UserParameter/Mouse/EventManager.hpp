#ifndef  USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP
# define USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/Mouse/Position.hpp"
# include "UserParameter/Mouse/Click.hpp"
# include "UserParameter/Mouse/Scroll.hpp"

# include "DataStruct/Point2D.hpp"

/*	instead of putting all the managing logic in the Window, put it here
*/



struct Window;

namespace UserParameter
{

namespace Mouse
{

struct EventManager
{
	private:
	Window * win;
	public:
	UserParameter::Mouse::ButtonRange Buttons;

	private:
	void (*CallbackClick)	(UserParameter::Mouse::Click);
	void (*CallbackScroll)	(UserParameter::Mouse::Scroll);
	void (*CallbackMove)	(UserParameter::Mouse::ButtonData);

	public:
	EventManager(Window * win);

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

	public:
	void ChangeCallbackClick(void (*func)(UserParameter::Mouse::Click));
	void ChangeCallbackScroll(void (*func)(UserParameter::Mouse::Scroll));
	void ChangeCallbackMove(void (*func)(UserParameter::Mouse::ButtonData));

	public:
	void RelayCallbackClick(UserParameter::Mouse::Click params);
	void RelayCallbackScroll(UserParameter::Mouse::Scroll params);
	void RelayCallbackMove(UserParameter::Mouse::ButtonData params);

	public:
	void RelayCallbackClick(int button, int action, int mods);
	void RelayCallbackScroll(float offset_x, float offset_y);
	void RelayCallbackMove(double x_pos, double y_pos);
};

};

};

#endif