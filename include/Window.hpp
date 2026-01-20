#ifndef  WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"
# include "DataStruct/Point2D.hpp"

# include "Display/WindowBufferSize2D.hpp"

# include "UserParameter/KeyBoard/KeyRange1.hpp"
# include "UserParameter/KeyBoard/KeyRange2.hpp"
# include "UserParameter/KeyBoard/Key.hpp"
# include "UserParameter/KeyBoard/Text.hpp"

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/Mouse/EventManager.hpp"



/*
	Crashes sometimes even with no Buffers Shaders or anything else
	I assume something in Window (Keys Mouse) is causing it
	or the glfw Stuff itself
*/



struct GLFWwindow;

struct Point3D;
struct Angle3D;

class Window
{
	private:
	static GLFWwindow * NormalWindow();

	private:
	public:
	GLFWwindow * glfw_window;
	UserParameter::KeyBoard::KeyRange2 Keys;
	UserParameter::Mouse::EventManager MouseManager;

	public:
	unsigned long long FrameNumberTerminate;

	public:
	void (*FrameFunc)	(double);
	void (*InitFunc)	();
	void (*FreeFunc)	();

	void (*ResizeFunc)	(const WindowBufferSize2D &);

	void (*KeyFunc)		(UserParameter::KeyBoard::Key);
	void (*TextFunc)	(UserParameter::KeyBoard::Text);

	public:
	WindowBufferSize2D Size;

	private:
	Point2D WindowCenter;
	Point2D BufferCenter;

	public:
	Color DefaultColor;

	public:
	Window();
	~Window();

	//public:
	//void Create();
	//void Delete();

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
	void ChangeCallback_CursorClick(void (*func)(UserParameter::Mouse::Click));
	void ChangeCallback_CursorScroll(void (*func)(UserParameter::Mouse::Scroll));
	void ChangeCallback_CursorMove(void (*func)(UserParameter::Mouse::Position));
	void ChangeCallback_CursorDrag(void (*func)(UserParameter::Mouse::Drag));

	public:
	Point3D MoveFromKeys(float speed) const;
	Angle3D SpinFromCursor(float speed) const;

	private:
	void RunGL_Setup();
	void Run_Init();
	void Run_Free();

	public:
	void Run();
	void Term();
};

#endif