#ifndef  USER_MOUSE_MANAGER_HPP
# define USER_MOUSE_MANAGER_HPP

# include "User/MouseState.hpp"

# include "User/Args/ClickArgs.hpp"
# include "User/Args/DragArgs.hpp"
# include "User/Args/MoveArgs.hpp"
# include "User/Args/ScrollArgs.hpp"

# include "Generics/Function/Pointer.hpp"

class Window;

struct MouseManager
{
	private:
	static const unsigned int StateNum = 8;

	private:
	Window &	window;
	MouseState	MouseStates[StateNum];
	public:
	VectorF2	Scroll;

	public:
	const MouseState & operator[](const MouseButtons & button) const;

	public:
	Function::Pointer<ClickArgs>	Callback_ClickEvent;
	Function::Pointer<MoveArgs>		Callback_MoveEvent;
	Function::Pointer<DragArgs>		Callback_DragEvent;
	Function::Pointer<ScrollArgs>	Callback_ScrollEvent;

	public:
	~MouseManager() = default;
	MouseManager() = delete;
	MouseManager(const MouseManager & other) = delete;
	MouseManager & operator=(const MouseManager & other) = delete;
	public:
	MouseManager(Window & win);

	public:
	bool	CursorModeIsLocked() const;
	void	CursorModeLock();
	void	CursorModeFree();
	void	CursorModeToggle();

	public:
	DisplayPosition		CursorPosition() const;
	void				CursorPositionPutCenter();

	public:
	void	Tick();

	private:
	void	UpdateClick(MouseButtons button, Action action, Modifier mods);
	void	UpdateScroll(VectorF2 scroll);
	void	UpdateMove(VectorF2 pos);
	void	UpdateDrag(VectorF2 pos);

	public:
	void	UpdateClick(int button, int action, int mods);
	void	UpdateScroll(float offset_x, float offset_y);
	void	UpdateMove(double x_pos, double y_pos);
};

#endif