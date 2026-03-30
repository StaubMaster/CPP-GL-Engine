#include "User/MouseManager.hpp"

#include "Window.hpp"
//#include <GLFW/glfw3.h>



MouseState & MouseManager::operator[](const MouseButtons & button)
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (MouseStates[i].MouseButton == button)
		{
			return MouseStates[i];
		}
	}
	throw "MouseManager[]: MouseButton not found.";
}



MouseManager::~MouseManager() { }
MouseManager::MouseManager(Window & win)
	: window(win)
	, MouseStates{
		MouseState(MouseButtons::Mouse1),
		MouseState(MouseButtons::Mouse2),
		MouseState(MouseButtons::Mouse3),
		MouseState(MouseButtons::Mouse4),
		MouseState(MouseButtons::Mouse5),
		MouseState(MouseButtons::Mouse6),
		MouseState(MouseButtons::Mouse7),
		MouseState(MouseButtons::Mouse8),
	}
{ }



bool MouseManager::CursorModeIsLocked() const
{
	return (glfwGetInputMode(window.glfw_window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED);
}
void MouseManager::CursorModeLock()
{
	glfwSetCursorPos(window.glfw_window, 0, 0);
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void MouseManager::CursorModeFree()
{
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window.glfw_window, 0, 0);
}
void MouseManager::CursorModeToggle()
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

DisplayPosition MouseManager::CursorPosition() const
{
	double x, y;
	glfwGetCursorPos(window.glfw_window, &x, &y);
	return DisplayPosition::FromWindowCorner(Point2D(x, y), window.Size);
}



void MouseManager::Tick()
{
	for (unsigned int i = 0; i < 8; i++)
	{
		MouseStates[i].Tick();
	}

	if (CursorModeIsLocked())
	{
		glfwSetCursorPos(window.glfw_window, 0, 0);
	}
}
void MouseManager::Update(MouseButtons button, Action action)
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (MouseStates[i].MouseButton == button)
		{
			MouseStates[i].Update(CursorPosition(), action);
		}
	}
}



void MouseManager::Invoke_ClickEvent(int button, int action, int mods)
{
	Update((MouseButtons)button, (Action)action);

	Callback_ClickEvent(ClickArgs((Modifier)mods, (Action)action, (MouseButtons)button, CursorPosition()));
}
void MouseManager::Invoke_ScrollEvent(float offset_x, float offset_y)
{
	Callback_ScrollEvent(ScrollArgs((Modifier)0, offset_x, offset_y, CursorPosition()));
}
void MouseManager::Invoke_MoveEvent(double x_pos, double y_pos)
{
	Point2D p(x_pos, y_pos);

	DisplayPosition pos;
	pos.Window.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Buffer.Corner = p; // one of these is wrong. calculat the first, then normal, then the other.
	pos.Window.Center = pos.Window.Corner - window.Size.Window.Half;
	pos.Buffer.Center = pos.Buffer.Corner - window.Size.Buffer.Half;
	pos.NormalAbs = pos.Window.Corner / window.Size.Window.Full;
	pos.NormalRel = pos.Window.Center / window.Size.Window.Half;

	MoveArgs args;
	args.Position = pos;
	Callback_MoveEvent(args);

	for (unsigned int i = 0; i < 8; i++)
	{
		if (MouseStates[i].State == State::Down)
		{
			DragArgs args;
			args.Origin = MouseStates[i].LastPressPosition;
			args.Position = pos;
			Callback_DragEvent(args);
		}
	}
}
