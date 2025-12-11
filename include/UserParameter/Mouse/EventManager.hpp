#ifndef  USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP
# define USER_PARAMETER_MOUSE_EVENNTMANAGER_HPP

# include "UserParameter/Mouse/ButtonRange.hpp"
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

	public:
	EventManager(Window * win);

	public:
	bool	CursorModeIsLocked() const;
	void	CursorModeLock();
	void	CursorModeFree();
	void	CursorModeToggle();

	Point2D CursorPixelPosition() const;
	Point2D CursorPixelCentered() const;

	public:
	void Update(int button, int action, int mods);
	void Tick();

	public:
	void ChangeCallbackClick(void (*func)(UserParameter::Mouse::Click));
	void ChangeCallbackScroll(void (*func)(UserParameter::Mouse::Scroll));

	public:
	void RelayCallbackClick(UserParameter::Mouse::Click params);
	void RelayCallbackScroll(UserParameter::Mouse::Scroll params);

	public:
	void RelayCallbackClick(int button, int action, int mods);
	void RelayCallbackScroll(float offset_x, float offset_y);
};

};

};

#endif