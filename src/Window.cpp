#include "Window.hpp"
#include "TimeMeasure.hpp"

#include "ValueType/Point3D.hpp"
#include "ValueType/Point2D.hpp"
#include "ValueType/EulerAngle3D.hpp"
#include "ValueType/Trans3D.hpp"

#include "Debug.hpp"
#include <sstream>

//#include "../glad/glad.h"
//#include <GLFW/glfw3.h>
#include "OpenGL.hpp"

#include <iostream>

#ifndef ENGINE_DIR
# error Engine Directory Unknown
# define ENGINE_DIR
#endif



GLFWwindow * Window::NormalWindow()
{
	Debug::Log << Debug::Tabs << "Window::NormalWindow()" << "  ....  " << Debug::Done;
	glfwSetErrorCallback(Callback_GLFW_Error);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow * win = glfwCreateWindow(640, 480, "Window", nullptr, nullptr);
	if (win == nullptr)
	{
		Debug::Log << "Window Making failed" << Debug::Done;
		throw "Window Failed";
	}
	glfwMakeContextCurrent(win);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw "glad load GL-Loader Failed";
	}
	Debug::Log << Debug::Tabs << "Window::NormalWindow()" << "  done  " << Debug::Done;
	return win;
}
void Window::MakeCallbacks()
{
	glfwSetWindowUserPointer(glfw_window, this);

	glfwSetFramebufferSizeCallback(glfw_window, Callback_GLFW_Resize);
	glfwSetKeyCallback(glfw_window, Callback_GLFW_Key);
	glfwSetCharCallback(glfw_window, Callback_GLFW_Text);

	glfwSetMouseButtonCallback(glfw_window, Callback_GLFW_CursorClick);
	glfwSetScrollCallback(glfw_window, Callback_GLFW_CursorScroll);
	glfwSetCursorPosCallback(glfw_window, Callback_GLFW_CursorMove);
}
void Window::MakeUserParemeters()
{
	Debug::Log << Debug::Tabs << "MakeUserParemeters" << "  ....  " << Debug::Done;

	// these arent all Keys that openGL provides
	// maybe just put all keys in one list, instead of subLists
	// it's < 400 keys so a for loop that checks and int should be fine
	//KeyBoardManager.Keys.KeyArrays[0] = UserParameter::KeyBoard::KeyRange1(32, 32);		//	Space
	//KeyBoardManager.Keys.KeyArrays[1] = UserParameter::KeyBoard::KeyRange1(48, 57);		//	Numbers
	//KeyBoardManager.Keys.KeyArrays[2] = UserParameter::KeyBoard::KeyRange1(65, 90);		//	Letters
	//KeyBoardManager.Keys.KeyArrays[3] = UserParameter::KeyBoard::KeyRange1(256, 269);	//	Control0
	//KeyBoardManager.Keys.KeyArrays[4] = UserParameter::KeyBoard::KeyRange1(290, 314);	//	Function
	//KeyBoardManager.Keys.KeyArrays[5] = UserParameter::KeyBoard::KeyRange1(320, 336);	//	KeyPad
	//KeyBoardManager.Keys.KeyArrays[6] = UserParameter::KeyBoard::KeyRange1(340, 348);	//	Control1

	//MouseManager.Buttons = UserParameter::Mouse::ButtonRange(0, 5);

	Debug::Log << Debug::Tabs << "MakeUserParemeters" << "  done  " << Debug::Done;
}





Window::~Window()
{
	Delete();
}
Window::Window()
	: glfw_window(nullptr)
	, LoopIsDone(false)
	, FrameNumberTerminate(0xFFFFFFFFFFFFFFFF)
	, DefaultColor(0.5f, 0.5f, 0.5f)
	, CallBack_Init()
	, CallBack_Free()
	, CallBack_Resize()
	, CallBack_Frame()
	, KeyBoardManager(*this)
	, MouseManager(*this)
{
	Debug::Log << Debug::Tabs << "  ++++  " << "Window" << "  ....  " << Debug::Done;
	Debug::Log << Debug::Tabs << "Engine Dir: " << ENGINE_DIR << Debug::Done;
	Debug::Log << Debug::TabInc;
	MakeUserParemeters();
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "  ++++  " << "Window" << "  done  " << Debug::Done;
}

Window::Window(const Window & other)
	: glfw_window(other.glfw_window)
	, LoopIsDone(other.LoopIsDone)
	, FrameNumberTerminate(other.FrameNumberTerminate)
	, DefaultColor(other.DefaultColor)
	, CallBack_Init(other.CallBack_Init)
	, CallBack_Free(other.CallBack_Free)
	, CallBack_Resize(other.CallBack_Resize)
	, CallBack_Frame(other.CallBack_Frame)
	, KeyBoardManager(*this)
	, MouseManager(*this)
{
	MakeUserParemeters();
}
Window & Window::operator=(const Window & other)
{
	glfw_window = other.glfw_window;
	LoopIsDone = other.LoopIsDone;
	FrameNumberTerminate = other.FrameNumberTerminate;
	DefaultColor = other.DefaultColor;
	CallBack_Init = other.CallBack_Init;
	CallBack_Free = other.CallBack_Free;
	CallBack_Resize = other.CallBack_Resize;
	CallBack_Frame = other.CallBack_Frame;
	return *this;
}



bool Window::Exists() const
{
	return (glfw_window != nullptr);
}
void Window::Create()
{
	Debug::Log << Debug::Tabs << "Window::Create()" << "  ....  " << Debug::Done;
	Debug::Log << Debug::TabInc;
	glfw_window = NormalWindow();
	MakeCallbacks();
	UpdateSize();
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "Window::Create()" << "  done  " << Debug::Done;
}
void Window::Delete()
{
	Debug::Log << Debug::Tabs << "Window::Delete()" << "  ....  " << Debug::Done;
	Debug::Log << Debug::TabInc;
	glfwDestroyWindow(glfw_window);
	glfw_window = nullptr;
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "Window::Delete()" << "  done  " << Debug::Done;
}
void Window::Quit()
{
	glfwSetWindowShouldClose(glfw_window, 1);
}



void Window::UpdateSize()
{
	if (glfw_window == nullptr) { return; }

	int w, h;

	Point2D winSize;
	glfwGetWindowSize(glfw_window, &w, &h);
	winSize = Point2D(w, h);

	Point2D bufSize;
	glfwGetFramebufferSize(glfw_window, &w, &h);
	bufSize = Point2D(w, h);

	Size.Change(winSize, bufSize);
}



void Window::Callback_GLFW_Error(int error, const char * description)
{
	std::cerr << "GLFW Error: " << error << ": " << description << "\n";
}



void Window::Callback_GLFW_Resize(GLFWwindow * window, int w, int h)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_Resize(w, h);
}
void Window::Callback_GLFW_CursorClick(GLFWwindow * window, int button, int action, int mods)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_CursorClick(button, action, mods);
}
void Window::Callback_GLFW_CursorScroll(GLFWwindow * window, double xOffset, double yOffset)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_CursorScroll(xOffset, yOffset);
}
void Window::Callback_GLFW_CursorMove(GLFWwindow * window, double xPos, double yPos)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_CursorMove(xPos, yPos);
}
void Window::Callback_GLFW_Key(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_Key(key, scancode, action, mods);
}
void Window::Callback_GLFW_Text(GLFWwindow * window, unsigned int codepoint)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_GLFW_Text(codepoint);
}



void Window::Callback_GLFW_Resize(int w, int h)
{
	glViewport(0, 0, w, h);
	UpdateSize();
	CallBack_Resize(Size);
}
void Window::Callback_GLFW_CursorClick(int button, int action, int mods)
{
	MouseManager.Invoke_ClickEvent(button, action, mods);
}
void Window::Callback_GLFW_CursorScroll(double xOffset, double yOffset)
{
	MouseManager.Invoke_ScrollEvent(xOffset, yOffset);
}
void Window::Callback_GLFW_CursorMove(double xPos, double yPos)
{
	MouseManager.Invoke_MoveEvent(xPos, yPos);
}
void Window::Callback_GLFW_Key(int key, int scancode, int action, int mods)
{
	KeyBoardManager.Invoke_KeyEvent(key, scancode, action, mods);
}
void Window::Callback_GLFW_Text(unsigned int codepoint)
{
	KeyBoardManager.Invoke_TextEvent(codepoint);
}





Point3D Window::MoveFromKeys() const
{
	Point3D move;
	if (KeyBoardManager[Keys::A].State == State::Down)				{ move.X -= 1; }
	if (KeyBoardManager[Keys::D].State == State::Down)				{ move.X += 1; }
	if (KeyBoardManager[Keys::S].State == State::Down)				{ move.Z -= 1; }
	if (KeyBoardManager[Keys::W].State == State::Down)				{ move.Z += 1; }
	if (KeyBoardManager[Keys::Space].State == State::Down)			{ move.Y += 1; }
	if (KeyBoardManager[Keys::LeftShift].State == State::Down)		{ move.Y -= 1; }
	return move;
}
EulerAngle3D Window::SpinFromCursor() const
{
	EulerAngle3D spin;
	DisplayPosition cursor = MouseManager.CursorPosition();
	spin.X1 = Angle::Radians(cursor.Window.Corner.Y);
	spin.Y2 = Angle::Radians(cursor.Window.Corner.X);
	return spin;
}
Trans3D Window::MoveSpinFromKeysCursor() const
{
	return Trans3D(
		MoveFromKeys(),
		SpinFromCursor()
	);
}



void Window::RunGL_Setup()
{
	GL::Enable(GL::Capability::CullFace);
	GL::CullFace(GL::Side::Back);
	GL::FrontFace(GL::FrontSide::Cw);

	GL::Enable(GL::Capability::DepthTest);
	GL::DepthMask(true);
	GL::DepthFunc(GL::Comparison::Less);
	GL::DepthRange(0, 1);
	GL::ClearDepth(1.0f);
}
void Window::Run_Init()
{
	if (CallBack_Init.Function != nullptr)
	{
		Debug::Log << "Window Init() ..." << Debug::Done;
		CallBack_Init();
		Debug::Log << "Window Init() done" << Debug::Done;
	}
}
void Window::Run_Free()
{
	if (CallBack_Free.Function != nullptr)
	{
		Debug::Log << "Window Free() ..." << Debug::Done;
		CallBack_Free();
		Debug::Log << "Window Free() done" << Debug::Done;
	}
}



void Window::ExitLoop()
{
	LoopIsDone = true;
}
void Window::RunLoop()
{
	try
	{
		RunGL_Setup();
		Run_Init();
		UpdateSize();
		CallBack_Resize(Size);
		Debug::Log << "Window Loop ..." << Debug::Done;
		std::cout << "Window Loop ..." << '\n';
		FrameTime frame_time(64.0f, 4.0f / 64.0f);
		frame_time.TimeNow = glfwGetTime();
		LoopIsDone = false;
		while (!LoopIsDone)
		{
			frame_time.Update(glfwGetTime());
			if (frame_time.Ready)
			{
				KeyBoardManager.Tick();
				MouseManager.Tick();
				glfwPollEvents();
				GL::ClearColor(DefaultColor.R, DefaultColor.G, DefaultColor.B, 1.0f);
				GL::Clear(GL::ClearMask::ColorBufferBit | GL::ClearMask::DepthBufferBit);
				CallBack_Frame(frame_time);
				glfwSwapBuffers(glfw_window);
				frame_time.Ready = false;
				frame_time.Number++;
			}
			if (frame_time.Number == FrameNumberTerminate)
			{
				LoopIsDone = true;
			}
			if (glfwWindowShouldClose(glfw_window))
			{
				LoopIsDone = true;
			}
		}
		Debug::Log << "Window Loop done" << Debug::Done;
		std::cout << "Window Loop done" << '\n';
	}
	catch (std::exception & ex)	{ std::cerr << "Exception: " << ex.what() << '\n'; }
	catch (std::string & str)	{ std::cerr << "std::string Exception: "<< str << '\n'; }
	catch (const char * str)	{ std::cerr << "const char * Exception: "<< str << '\n'; }
	catch (...)					{ std::cerr << "Unknown Exception\n"; }
	Run_Free();
}
