#include "User/MouseManager.hpp"

#include "Window.hpp"
//#include <GLFW/glfw3.h>



const MouseState & MouseManager::operator[](const MouseButtons & button) const
{
	for (unsigned int i = 0; i < StateNum; i++)
	{
		if (MouseStates[i].Button == button)
		{
			return MouseStates[i];
		}
	}
	throw "MouseManager[]: MouseButton not found.";
}



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
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window.glfw_window, 0, 0);
}
void MouseManager::CursorModeFree()
{
	glfwSetCursorPos(window.glfw_window, 0, 0);
	glfwSetInputMode(window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
void MouseManager::CursorModeToggle()
{
	if (CursorModeIsLocked())
	{
		CursorModeFree();
	}
	else
	{
		CursorModeLock();
	}
}

// Cache CursorPosition when Tick is called ?
// or only Calculate when Cursor Moves ?
DisplayPosition MouseManager::CursorPosition() const
{
	double x, y;
	glfwGetCursorPos(window.glfw_window, &x, &y);
	return window.Size.PosFromWindowFull(VectorF2(x, y));
}
void MouseManager::CursorPositionPutCenter()
{
	if (CursorModeIsLocked())
	{
		glfwSetCursorPos(window.glfw_window, 0, 0);
	}
}



void MouseManager::Tick()
{
	for (unsigned int i = 0; i < StateNum; i++)
	{
		MouseStates[i].Tick();
	}
	Scroll = VectorF2();
}
void MouseManager::UpdateClick(MouseButtons button, Action action, Modifier mods)
{
	for (unsigned int i = 0; i < StateNum; i++)
	{
		if (MouseStates[i].Button == button)
		{
			MouseStates[i].Update(CursorPosition(), action);
		}
	}

	Callback_ClickEvent.TryInvoke(ClickArgs(button, action, mods, CursorPosition()));
}
void MouseManager::UpdateScroll(VectorF2 scroll)
{
	Scroll += scroll;

	Callback_ScrollEvent.TryInvoke(ScrollArgs(scroll, Modifier::None, CursorPosition()));
}
void MouseManager::UpdateMove(VectorF2 pos)
{
	DisplayPosition display_pos = window.Size.PosFromWindowFull(pos);

	Callback_MoveEvent.TryInvoke(MoveArgs(display_pos));

	UpdateDrag(pos);
}
void MouseManager::UpdateDrag(VectorF2 pos)
{
	DisplayPosition display_pos = window.Size.PosFromWindowFull(pos);
	for (unsigned int i = 0; i < StateNum; i++)
	{
		MouseState & state = MouseStates[i];
		if (state.State == State::Down)
		{
			if (!state.IsDragging)
			{
				state.IsDragging = true;
				Callback_DragEvent.TryInvoke(DragArgs(state.Button, Action::Press, Modifier::None, state.LastPressPosition));
			}
			if (state.IsDragging)
			{
				Callback_DragEvent.TryInvoke(DragArgs(state.Button, Action::Repeat, Modifier::None, display_pos));
			}
		}
	}
	// no Drag Release
}



void MouseManager::UpdateClick(int button, int action, int mods)
{
	UpdateClick((MouseButtons)button, (Action)action, (Modifier)mods);
}
void MouseManager::UpdateScroll(float offset_x, float offset_y)
{
	UpdateScroll(VectorF2(offset_x, offset_y));
}
void MouseManager::UpdateMove(double x_pos, double y_pos)
{
	UpdateMove(VectorF2(x_pos, y_pos));
}
