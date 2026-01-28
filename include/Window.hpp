#ifndef  WINDOW_HPP
# define WINDOW_HPP

# include "ValueType/ColorF4.hpp"
# include "ValueType/Point2D.hpp"

# include "Function/Pointer.hpp"

# include "Display/WindowBufferSize2D.hpp"

# include "UserParameter/KeyBoard/KeyRange1.hpp"
# include "UserParameter/KeyBoard/KeyRange2.hpp"
# include "UserParameter/KeyBoard/Key.hpp"
# include "UserParameter/KeyBoard/Text.hpp"

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/Mouse/EventManager.hpp"



struct GLFWwindow;

struct Point3D;
struct Angle3D;
struct Trans3D;

class Window
{
	private:
	static GLFWwindow * NormalWindow();
	void MakeCallbacks();
	void MakeUserParemeters();

	public:
	GLFWwindow * glfw_window;

	public:
	unsigned long long FrameNumberTerminate;

	public:
	FunctionPointer<double>	FrameCallBack;
	FunctionPointer<>		InitCallBack;
	FunctionPointer<>		FreeCallBack;
	FunctionPointer<const WindowBufferSize2D &>		ResizeCallBack;
	FunctionPointer<UserParameter::KeyBoard::Key>	KeyCallBack;
	FunctionPointer<UserParameter::KeyBoard::Text>	TextCallBack;

	public:
	UserParameter::KeyBoard::KeyRange2 Keys;
	UserParameter::Mouse::EventManager MouseManager;
	ColorF4 DefaultColor;

	public:
	WindowBufferSize2D Size;
	private:
	Point2D WindowCenter;
	Point2D BufferCenter;

	public:
	Window();
	Window(const Window & other);
	Window & operator=(const Window & other);
	~Window();

	public:
//	bool Exists() const;
	void Create();
	void Delete();

/*
	make sure that all functions that require the window to exist
	check that it actually exists
*/

	public:
	//void ChangeSize(Point2D size);
	//void ChangeDefaultColor(ColorF4 color);

	private:
	void UpdateSize();

	private:
	static void Callback_Error(int error, const char * decription);

	private:
	static void Callback_Resize(GLFWwindow * window, int w, int h);
	static void Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods);
	static void Callback_Text(GLFWwindow * window, unsigned int codepoint);

	//	Put these into MouseEventManager
	static void Callback_CursorClick(GLFWwindow * window, int button, int action, int mods);
	static void Callback_CursorScroll(GLFWwindow * window, double xOffset, double yOffset);
	static void Callback_CursorMove(GLFWwindow * window, double xPos, double yPos);

	private:
	void Callback_Resize(int w, int h);
	void Callback_Key(int key, int scancode, int action, int mods);
	void Callback_Text(unsigned int codepoint);

	//	Put these into MouseEventManager
	void Callback_CursorClick(int button, int action, int mods);
	void Callback_CursorScroll(double xOffset, double yOffset);
	void Callback_CursorMove(double xPos, double yPos);

	public:
	void ChangeCallback_CursorClick(BaseFunction<void, UserParameter::Mouse::Click> * func);
	void ChangeCallback_CursorScroll(BaseFunction<void, UserParameter::Mouse::Scroll> * func);
	void ChangeCallback_CursorMove(BaseFunction<void, UserParameter::Mouse::Position> * func);
	void ChangeCallback_CursorDrag(BaseFunction<void, UserParameter::Mouse::Drag> * func);

	public:
	Point3D MoveFromKeys() const;
	Angle3D SpinFromCursor() const;
	Trans3D MoveSpinFromKeysCursor() const;

	private:
	void RunGL_Setup();
	void Run_Init();
	void Run_Free();

	public:
	void Run();
	void Term();
};

#endif