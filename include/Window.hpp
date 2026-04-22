#ifndef  WINDOW_HPP
# define WINDOW_HPP

# include "FrameTime.hpp"

# include "Display/DisplaySize.hpp"
# include "Display/DisplayPosition.hpp"

# include "User/KeyBoardManager.hpp"
# include "User/MouseManager.hpp"

# include "ValueType/ColorF4.hpp"
# include "ValueType/Point2D.hpp"

# include "Miscellaneous/Function/Pointer.hpp"



struct GLFWwindow;

//struct Point3D;
struct VectorF3; typedef VectorF3 Point3D;
struct EulerAngle3D;
struct Trans3D;

class Window
{
	private:
	static GLFWwindow * NormalWindow();
	void MakeCallbacks();
	void MakeUserParemeters();

	public:
	GLFWwindow * glfw_window;

	private:
	bool				LoopIsDone;
	public:
	unsigned long long	FrameNumberTerminate;

	public:
	DisplaySize		Size;

	public:
	ColorF4			DefaultColor;

	public:
	FunctionPointer<>				CallBack_Init;
	FunctionPointer<>				CallBack_Free;
	FunctionPointer<DisplaySize>	CallBack_Resize;

	//  Frame() / Draw()
	//    just Draws
	//    maybe minimal Updates, like Uniforms ?
	//  UpdateBuffers()
	//    puts Data into Buffers
	//    puts data into Uniforms ?
	//    Data needs to be ready
	//  Update()
	//    UpdateGeneral()
	//      Updates non OpenGL stuff
	//      make this one so it could be run on a seperate Thread
	FunctionPointer<FrameTime>		CallBack_Frame;

	public:
	::KeyBoardManager	KeyBoardManager;
	::MouseManager		MouseManager;

	const MouseState & operator[](const MouseButtons & button) const;
	const KeyState & operator[](const Keys & key) const;

	public:
	~Window();
	Window();
	Window(const Window & other);
	Window & operator=(const Window & other);

	// GLFW Window Stuff
	public:
	bool	Exists() const;
	void	Create();
	void	Delete();
	void	Quit();

	public:
	//void ChangeSize(Point2D size);
	//void ChangeDefaultColor(ColorF4 color);

	private:
	void UpdateSize();

	private:
	static void Callback_GLFW_Error(int error, const char * decription);

	private:
	static void Callback_GLFW_Resize(GLFWwindow * window, int w, int h);
	static void Callback_GLFW_CursorClick(GLFWwindow * window, int button, int action, int mods);
	static void Callback_GLFW_CursorScroll(GLFWwindow * window, double xOffset, double yOffset);
	static void Callback_GLFW_CursorMove(GLFWwindow * window, double xPos, double yPos);
	static void Callback_GLFW_Key(GLFWwindow * window, int key, int scancode, int action, int mods);
	static void Callback_GLFW_Text(GLFWwindow * window, unsigned int codepoint);

	private:
	void Callback_GLFW_Resize(int w, int h);
	void Callback_GLFW_CursorClick(int button, int action, int mods);
	void Callback_GLFW_CursorScroll(double xOffset, double yOffset);
	void Callback_GLFW_CursorMove(double xPos, double yPos);
	void Callback_GLFW_Key(int key, int scancode, int action, int mods);
	void Callback_GLFW_Text(unsigned int codepoint);

	public:
	Point3D MoveFromKeys() const;
	EulerAngle3D SpinFromCursor() const;
	Trans3D MoveSpinFromKeysCursor() const;

	private:
	void RunGL_Setup();
	void Run_Init();
	void Run_Free();

	public:
	void	ExitLoop();
	void	RunLoop();
};

#endif