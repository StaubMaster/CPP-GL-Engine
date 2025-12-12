#include "UserParameter/Mouse/EventManager.hpp"
#include "Window.hpp"
#include "OpenGL/openGL.h"



UserParameter::Mouse::EventManager::EventManager(Window * win) :
	win(win),
	Buttons(),
	CallbackClick(NULL),
	CallbackScroll(NULL)
{ }



void UserParameter::Mouse::EventManager::Tick()
{
	Buttons.Tick();
}
void UserParameter::Mouse::EventManager::UpdateClick(int button, int action, int mods)
{
	Buttons.Update(CursorPixelPosition(), Haptic::Code(button), Haptic::Action(action));
	(void)mods;
}



bool UserParameter::Mouse::EventManager::CursorModeIsLocked() const
{
	return (glfwGetInputMode(win -> win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED);
}
void UserParameter::Mouse::EventManager::CursorModeFree()
{
	glfwSetCursorPos(win -> win, 0, 0);
	glfwSetInputMode(win -> win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void UserParameter::Mouse::EventManager::CursorModeLock()
{
	glfwSetInputMode(win -> win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(win -> win, 0, 0);
}
void UserParameter::Mouse::EventManager::CursorModeToggle()
{
	int mode = glfwGetInputMode(win -> win, GLFW_CURSOR);
	if (mode == GLFW_CURSOR_DISABLED)
	{
		CursorModeFree();
	}
	else
	{
		CursorModeLock();
	}
}



UserParameter::Mouse::Position UserParameter::Mouse::EventManager::CursorPixelPosition() const
{
	double x, y;
	glfwGetCursorPos(win -> win, &x, &y);
	UserParameter::Mouse::Position pos;
	pos.Absolute.X = x;
	pos.Absolute.Y = y;
	return pos;
}
/*UserParameter::Mouse::Position UserParameter::Mouse::EventManager::CursorPixelCentered() const
{
	if (CursorModeIsLocked()) { return Point2D(0, 0); }

	Point2D p = CursorPixelPosition();

	p.X = (p.X - ((win -> ViewPortSizeRatio).Size.X / 2));
	p.Y = (((win -> ViewPortSizeRatio).Size.Y / 2) - p.Y);

	p.X = p.X / ((win -> ViewPortSizeRatio).Size.X * (win -> ViewPortSizeRatio).Ratio.X);
	p.Y = p.Y / ((win -> ViewPortSizeRatio).Size.Y * (win -> ViewPortSizeRatio).Ratio.Y);

	p.X = p.X * 2;
	p.Y = p.Y * 2;

	return p;
}*/



void UserParameter::Mouse::EventManager::ChangeCallbackClick(void (*func)(UserParameter::Mouse::Click))
{
	CallbackClick = func;
}
void UserParameter::Mouse::EventManager::ChangeCallbackScroll(void (*func)(UserParameter::Mouse::Scroll))
{
	CallbackScroll = func;
}
void UserParameter::Mouse::EventManager::ChangeCallbackMove(void (*func)(UserParameter::Mouse::ButtonData))
{
	CallbackMove = func;
}

void UserParameter::Mouse::EventManager::RelayCallbackClick(UserParameter::Mouse::Click params)
{
	if (CallbackClick != NULL) { CallbackClick(params); }
}
void UserParameter::Mouse::EventManager::RelayCallbackScroll(UserParameter::Mouse::Scroll params)
{
	if (CallbackScroll != NULL) { CallbackScroll(params); }
}
void UserParameter::Mouse::EventManager::RelayCallbackMove(UserParameter::Mouse::ButtonData params)
{
	if (CallbackMove != NULL) { CallbackMove(params); }
}

void UserParameter::Mouse::EventManager::RelayCallbackClick(int button, int action, int mods)
{
	UserParameter::Mouse::Click params;
	params.Code = button;
	params.Action = action;
	params.Mods = mods;
	params.Position = CursorPixelPosition();
	RelayCallbackClick(params);
}
void UserParameter::Mouse::EventManager::RelayCallbackScroll(float offset_x, float offset_y)
{
	UserParameter::Mouse::Scroll params;
	params.X = offset_x;
	params.Y = offset_y;
	RelayCallbackScroll(params);
}
void UserParameter::Mouse::EventManager::RelayCallbackMove(double x_pos, double y_pos)
{
	(void)x_pos;
	(void)y_pos;
	/*	look for what buttons are down
		Drag Callback for all those
	*/
	//RelayCallbackMove(params);
}
