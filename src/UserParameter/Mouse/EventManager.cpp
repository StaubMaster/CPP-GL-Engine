#include "UserParameter/Mouse/EventManager.hpp"
#include "UserParameter/MouseInclude.hpp"

#include "Window.hpp"
#include <GLFW/glfw3.h>



UserParameter::Mouse::EventManager::EventManager(Window & win) :
	window(win),
	Buttons(),
	CallbackClick(),
	CallbackScroll(),
	CallbackMove(),
	CallbackDrag()
{ }
UserParameter::Mouse::EventManager::~EventManager()
{ }



bool UserParameter::Mouse::EventManager::CursorModeIsLocked() const
{
	return (glfwGetInputMode(window.glfw_window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED);
}
void UserParameter::Mouse::EventManager::CursorModeFree()
{
	glfwSetCursorPos(window.glfw_window, 0, 0);
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void UserParameter::Mouse::EventManager::CursorModeLock()
{
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window.glfw_window, 0, 0);
}
void UserParameter::Mouse::EventManager::CursorModeToggle()
{
	int mode = glfwGetInputMode(window.glfw_window, GLFW_CURSOR);
	if (mode == GLFW_CURSOR_DISABLED)
	{
		CursorModeFree();
	}
	else
	{
		CursorModeLock();
	}
}



DisplayPosition UserParameter::Mouse::EventManager::CursorPosition() const
{
	double x, y;
	glfwGetCursorPos(window.glfw_window, &x, &y);
	Point2D p(x, y);

	DisplayPosition pos;
	pos.Window.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Buffer.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Window.Center = pos.Window.Corner - window.Size.Window.Half;
	pos.Buffer.Center = pos.Buffer.Corner - window.Size.Buffer.Half;
	pos.NormalAbs = pos.Window.Corner / window.Size.Window.Full;
	pos.NormalRel = pos.Window.Center / window.Size.Window.Half;
	return pos;
}
/*UserParameter::Mouse::Position UserParameter::Mouse::EventManager::CursorPixelPosition() const
{
	double x, y;
	glfwGetCursorPos(window.glfw_window, &x, &y);

	UserParameter::Mouse::Position pos;
	pos.Absolute.X = x;
	pos.Absolute.Y = y;
	return pos;
}*/
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



void UserParameter::Mouse::EventManager::Tick()
{
	Buttons.Tick();
	if (CursorModeIsLocked())
	{
		glfwSetCursorPos(window.glfw_window, 0, 0);
	}
}
void UserParameter::Mouse::EventManager::UpdateClick(int button, int action, int mods)
{
	Buttons.Update(CursorPosition(), Haptic::Code(button), Haptic::Action(action));

	UserParameter::Mouse::Click params;
	params.Code = button;
	params.Action = action;
	params.Mods = mods;
	params.Position = CursorPosition();
	CallbackClick(params);
}
void UserParameter::Mouse::EventManager::UpdateScroll(float offset_x, float offset_y)
{
	UserParameter::Mouse::Scroll params;
	params.X = offset_x;
	params.Y = offset_y;
	CallbackScroll(params);
}
void UserParameter::Mouse::EventManager::UpdateMove(double x_pos, double y_pos)
{
	Point2D p(x_pos, y_pos);

	DisplayPosition pos;
	pos.Window.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Buffer.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Window.Center = pos.Window.Corner - window.Size.Window.Half;
	pos.Buffer.Center = pos.Buffer.Corner - window.Size.Buffer.Half;
	pos.NormalAbs = pos.Window.Corner / window.Size.Window.Full;
	pos.NormalRel = pos.Window.Center / window.Size.Window.Half;

	CallbackMove(pos);
	/*	Dragging
			check if any Buttons id Down
			change current Pos to pos
			call Drag function
	*/
	for (unsigned int i = 0; i < Buttons.ButtonsCount; i++)
	{
		//	this uses the index as a token. only works because MouseButton Tokens are identical to Indexes
		UserParameter::Mouse::ButtonData & data = Buttons[i];
		if (data.State.IsDown())
		{
			UserParameter::Mouse::Drag params;
			//params.Code = data.State;
			//params.Mods	//	would need to store Mods for this
			params.Origin = data.LastPressPosition;
			params.Position = pos;
			CallbackDrag(params);
		}
	}
}
