#include "Window.hpp"
#include "TimeMeasure.hpp"

#include "ValueType/Point3D.hpp"
#include "ValueType/Angle3D.hpp"
#include "ValueType/Point2D.hpp"
#include "ValueType/Trans3D.hpp"
#include "UserParameter/MouseInclude.hpp"

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
	glfwSetErrorCallback(Callback_Error);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow * win = glfwCreateWindow(640, 480, "Window", NULL, NULL);
	if (win == NULL)
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

	glfwSetFramebufferSizeCallback(glfw_window, Callback_Resize);
	glfwSetKeyCallback(glfw_window, Callback_Key);
	glfwSetCharCallback(glfw_window, Callback_Text);

	glfwSetMouseButtonCallback(glfw_window, Callback_CursorClick);
	glfwSetScrollCallback(glfw_window, Callback_CursorScroll);
	glfwSetCursorPosCallback(glfw_window, Callback_CursorMove);
}
void Window::MakeUserParemeters()
{
	Debug::Log << Debug::Tabs << "MakeUserParemeters" << "  ....  " << Debug::Done;

	KeyBoardManager.Keys.KeyArrays[0] = UserParameter::KeyBoard::KeyRange1(32, 32);		//	Space
	KeyBoardManager.Keys.KeyArrays[1] = UserParameter::KeyBoard::KeyRange1(48, 57);		//	Numbers
	KeyBoardManager.Keys.KeyArrays[2] = UserParameter::KeyBoard::KeyRange1(65, 90);		//	Letters
	KeyBoardManager.Keys.KeyArrays[3] = UserParameter::KeyBoard::KeyRange1(256, 269);	//	Control0
	KeyBoardManager.Keys.KeyArrays[4] = UserParameter::KeyBoard::KeyRange1(290, 314);	//	Function
	KeyBoardManager.Keys.KeyArrays[5] = UserParameter::KeyBoard::KeyRange1(320, 336);	//	KeyPad
	KeyBoardManager.Keys.KeyArrays[6] = UserParameter::KeyBoard::KeyRange1(340, 348);	//	Control1

	MouseManager.Buttons = UserParameter::Mouse::ButtonRange(0, 5);

	Debug::Log << Debug::Tabs << "MakeUserParemeters" << "  done  " << Debug::Done;
}





Window::Window() :
	glfw_window(NULL),
	FrameNumberTerminate(0xFFFFFFFFFFFFFFFF),
	FrameCallBack(),
	InitCallBack(),
	FreeCallBack(),
	ResizeCallBack(),
	KeyBoardManager(*this, 7),
	MouseManager(*this),
	DefaultColor(0.5f, 0.5f, 0.5f)
{
	Debug::Log << Debug::Tabs << "  ++++  " << "Window" << "  ....  " << Debug::Done;
	Debug::Log << Debug::Tabs << "Engine Dir: " << ENGINE_DIR << Debug::Done;
	Debug::Log << Debug::TabInc;
	MakeUserParemeters();
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "  ++++  " << "Window" << "  done  " << Debug::Done;
}
Window::~Window()
{ }

Window::Window(const Window & other) :
	glfw_window(other.glfw_window),
	FrameNumberTerminate(other.FrameNumberTerminate),
	FrameCallBack(other.FrameCallBack),
	InitCallBack(other.InitCallBack),
	FreeCallBack(other.FreeCallBack),
	ResizeCallBack(other.ResizeCallBack),
	KeyBoardManager(*this, 7),
	MouseManager(*this),
	DefaultColor(other.DefaultColor)
{
	MakeUserParemeters();
}
Window & Window::operator=(const Window & other)
{
	glfw_window = other.glfw_window;
	FrameNumberTerminate = 0xFFFFFFFFFFFFFFFF;
	FrameCallBack = other.FrameCallBack;
	InitCallBack = other.InitCallBack;
	FreeCallBack = other.FreeCallBack;
	ResizeCallBack = other.ResizeCallBack;
	DefaultColor = other.DefaultColor;
	return *this;
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
	glfwDestroyWindow(glfw_window);
	glfw_window = NULL;
}



void Window::UpdateSize()
{
	if (glfw_window == NULL) { return; }

	int w, h;

	Point2D winSize;
	glfwGetWindowSize(glfw_window, &w, &h);
	winSize = Point2D(w, h);

	Point2D bufSize;
	glfwGetFramebufferSize(glfw_window, &w, &h);
	bufSize = Point2D(w, h);

	Size.Change(winSize, bufSize);
	WindowCenter = winSize * 0.5f;
	BufferCenter = bufSize * 0.5f;
}



void Window::Callback_Error(int error, const char * description)
{
	std::cerr << "GLFW Error: " << error << ": " << description << "\n";
}



void Window::Callback_Resize(GLFWwindow * window, int w, int h)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_Resize(w, h);
}
void Window::Callback_CursorClick(GLFWwindow * window, int button, int action, int mods)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_CursorClick(button, action, mods);
}
void Window::Callback_CursorScroll(GLFWwindow * window, double xOffset, double yOffset)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_CursorScroll(xOffset, yOffset);
}
void Window::Callback_CursorMove(GLFWwindow * window, double xPos, double yPos)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_CursorMove(xPos, yPos);
}
void Window::Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_Key(key, scancode, action, mods);
}
void Window::Callback_Text(GLFWwindow * window, unsigned int codepoint)
{
	Window * win = ((Window *)glfwGetWindowUserPointer(window));
	win -> Callback_Text(codepoint);
}



void Window::Callback_Resize(int w, int h)
{
	glViewport(0, 0, w, h);
	UpdateSize();
	ResizeCallBack(Size);
}
void Window::Callback_CursorClick(int button, int action, int mods)
{
	MouseManager.UpdateClick(button, action, mods);
}
void Window::Callback_CursorScroll(double xOffset, double yOffset)
{
	MouseManager.UpdateScroll(xOffset, yOffset);
}
void Window::Callback_CursorMove(double xPos, double yPos)
{
	MouseManager.UpdateMove(xPos, yPos);
}
void Window::Callback_Key(int key, int scancode, int action, int mods)
{
	KeyBoardManager.UpdateKey(key, scancode, action, mods);
}
void Window::Callback_Text(unsigned int codepoint)
{
	KeyBoardManager.UpdateText(codepoint);
}





Point3D Window::MoveFromKeys() const
{
	Point3D move;
	if (KeyBoardManager.Keys[GLFW_KEY_A].IsDown())				{ move.X -= 1; }
	if (KeyBoardManager.Keys[GLFW_KEY_D].IsDown())				{ move.X += 1; }
	if (KeyBoardManager.Keys[GLFW_KEY_S].IsDown())				{ move.Z -= 1; }
	if (KeyBoardManager.Keys[GLFW_KEY_W].IsDown())				{ move.Z += 1; }
	if (KeyBoardManager.Keys[GLFW_KEY_SPACE].IsDown())			{ move.Y += 1; }
	if (KeyBoardManager.Keys[GLFW_KEY_LEFT_SHIFT].IsDown())		{ move.Y -= 1; }
	return move;
}
Angle3D Window::SpinFromCursor() const
{
	Angle3D spin;
	Point2D cursor = MouseManager.CursorPixelPosition().Absolute;
	spin.X.FromRadians(+cursor.X);
	spin.Y.FromRadians(-cursor.Y);
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
	if (InitCallBack.Function != NULL)
	{
		Debug::Log << "Window Init() ..." << Debug::Done;
		InitCallBack();
		Debug::Log << "Window Init() done" << Debug::Done;
	}
}
void Window::Run_Free()
{
	if (FreeCallBack.Function != NULL)
	{
		Debug::Log << "Window Free() ..." << Debug::Done;
		FreeCallBack();
		Debug::Log << "Window Free() done" << Debug::Done;
	}
}
void Window::Run()
{
	try
	{
		RunGL_Setup();
		Run_Init();
		UpdateSize();
		ResizeCallBack(Size);
		Debug::Log << "Window Loop ..." << Debug::Done;
		std::cout << "Window Loop ..." << '\n';
		double FrameTimeLast = glfwGetTime();
		unsigned long long FrameNumber = 0;
		while (!glfwWindowShouldClose(glfw_window))
		{
			double FrameTimeCurr = glfwGetTime();
			double FrameTimeDelta = FrameTimeCurr - FrameTimeLast;
			if (FrameTimeDelta >= (1.0 / 64.0))
			{
				KeyBoardManager.Tick();
				MouseManager.Tick();
				glfwPollEvents();
				GL::ClearColor(DefaultColor.R, DefaultColor.G, DefaultColor.B, 1.0f);
				GL::Clear(GL::ClearMask::ColorBufferBit | GL::ClearMask::DepthBufferBit);
				FrameCallBack(FrameTimeDelta);
				glfwSwapBuffers(glfw_window);
				FrameTimeLast = FrameTimeCurr;
				FrameNumber++;
			}
			if (FrameNumber == FrameNumberTerminate)
			{ glfwSetWindowShouldClose(glfw_window, 1); }
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
