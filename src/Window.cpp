#include "Window.hpp"
#include "TimeMeasure.hpp"

#include "ValueType/Point3D.hpp"
#include "ValueType/Angle3D.hpp"
#include "ValueType/Point2D.hpp"
#include "UserParameter/MouseInclude.hpp"

#include "Debug.hpp"
#include <sstream>

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#ifndef ENGINE_DIR
# error Engine Directory Unknown
# define ENGINE_DIR
#endif



GLFWwindow * Window::NormalWindow()
{
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
	return win;
}



Window::Window() :
	glfw_window(NormalWindow()),
	Keys(7),
	MouseManager(*this)
{
	Debug::Log << "Engine Dir: " << ENGINE_DIR << Debug::Done;

	Keys.KeyArrays[0] = UserParameter::KeyBoard::KeyRange1(32, 32);		//	Space
	Keys.KeyArrays[1] = UserParameter::KeyBoard::KeyRange1(48, 57);		//	Numbers
	Keys.KeyArrays[2] = UserParameter::KeyBoard::KeyRange1(65, 90);		//	Letters
	Keys.KeyArrays[3] = UserParameter::KeyBoard::KeyRange1(256, 269);	//	Control0
	Keys.KeyArrays[4] = UserParameter::KeyBoard::KeyRange1(290, 314);	//	Function
	Keys.KeyArrays[5] = UserParameter::KeyBoard::KeyRange1(320, 336);	//	KeyPad
	Keys.KeyArrays[6] = UserParameter::KeyBoard::KeyRange1(340, 348);	//	Control1

	MouseManager.Buttons = UserParameter::Mouse::ButtonRange(0, 5);

	glfwSetWindowUserPointer(glfw_window, this);

	glfwSetFramebufferSizeCallback(glfw_window, Callback_Resize);
	glfwSetKeyCallback(glfw_window, Callback_Key);
	glfwSetCharCallback(glfw_window, Callback_Text);

	glfwSetMouseButtonCallback(glfw_window, Callback_CursorClick);
	glfwSetScrollCallback(glfw_window, Callback_CursorScroll);
	glfwSetCursorPosCallback(glfw_window, Callback_CursorMove);

	FrameNumberTerminate = 0xFFFFFFFFFFFFFFFF;

	FrameFunc = NULL;
	InitFunc = NULL;
	FreeFunc = NULL;

	ResizeFunc = NULL;

	KeyFunc = NULL;
	TextFunc = NULL;

	UpdateSize();

	DefaultColor = ColorF4(0.5f, 0.5f, 0.5f);
}
Window::~Window()
{ }



void Window::UpdateSize()
{
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



void Window::Callback_Resize(int w, int h)
{
	glViewport(0, 0, w, h);
	UpdateSize();
	if (ResizeFunc != NULL) { ResizeFunc(Size); }
}
void Window::Callback_Key(int key, int scancode, int action, int mods)
{
	if (Keys.Has(key))
	{
		UserParameter::Haptic::State & state = Keys[key];
		state.Update(UserParameter::Haptic::Action(action));
	}

	if (KeyFunc != NULL) { KeyFunc(UserParameter::KeyBoard::Key(key, scancode, action, mods)); }
}
void Window::Callback_Text(unsigned int codepoint)
{
	if (TextFunc != NULL) { TextFunc(UserParameter::KeyBoard::Text(codepoint)); }
}

void Window::Callback_CursorClick(int button, int action, int mods)
{
	MouseManager.UpdateClick(button, action, mods);
	(void)button;
	(void)action;
	(void)mods;
}
void Window::Callback_CursorScroll(double xOffset, double yOffset)
{
	MouseManager.UpdateScroll(xOffset, yOffset);
	(void)xOffset;
	(void)yOffset;
}
void Window::Callback_CursorMove(double xPos, double yPos)
{
	MouseManager.UpdateMove(xPos, yPos);
	(void)xPos;
	(void)yPos;
}



void Window::ChangeCallback_CursorClick(void (*func)(UserParameter::Mouse::Click))
{
	MouseManager.ChangeCallbackClick(func);
	(void)func;
}
void Window::ChangeCallback_CursorScroll(void (*func)(UserParameter::Mouse::Scroll))
{
	MouseManager.ChangeCallbackScroll(func);
	(void)func;
}
void Window::ChangeCallback_CursorMove(void (*func)(UserParameter::Mouse::Position))
{
	MouseManager.ChangeCallbackMove(func);
	(void)func;
}
void Window::ChangeCallback_CursorDrag(void (*func)(UserParameter::Mouse::Drag))
{
	MouseManager.ChangeCallbackDrag(func);
	(void)func;
}





Point3D Window::MoveFromKeys(float speed) const
{
	Point3D move;

	if (Keys[GLFW_KEY_A].IsDown())				{ move.X -= speed; }
	if (Keys[GLFW_KEY_D].IsDown())				{ move.X += speed; }
	if (Keys[GLFW_KEY_S].IsDown())				{ move.Z -= speed; }
	if (Keys[GLFW_KEY_W].IsDown())				{ move.Z += speed; }
	if (Keys[GLFW_KEY_SPACE].IsDown())			{ move.Y += speed; }
	if (Keys[GLFW_KEY_LEFT_SHIFT].IsDown())		{ move.Y -= speed; }
	if (Keys[GLFW_KEY_LEFT_CONTROL].IsDown())	{ move = move * 10; }
	(void)speed;

	return move;
}
Angle3D Window::SpinFromCursor(float speed) const
{
	Angle3D spin;

	Point2D cursor = MouseManager.CursorPixelPosition().Absolute;

	spin.X = (+cursor.X) * speed;
	spin.Y = (-cursor.Y) * speed;
	spin.Z = 0;

	return spin;
}


void Window::RunGL_Setup()
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glDepthRange(0, 1);
	glClearDepth(1.0f);
}
void Window::Run_Init()
{
	if (InitFunc != NULL)
	{
		Debug::Log << "Window Init() ..." << Debug::Done;
		InitFunc();
		Debug::Log << "Window Init() done" << Debug::Done;
	}
}
void Window::Run_Free()
{
	if (FreeFunc != NULL)
	{
		Debug::Log << "Window Free() ..." << Debug::Done;
		FreeFunc();
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
		if (ResizeFunc != NULL) { ResizeFunc(Size); }
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
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glClearColor(DefaultColor.R, DefaultColor.G, DefaultColor.B, 1.0f);
				FrameFunc(FrameTimeDelta);
				glfwSwapBuffers(glfw_window);
				Keys.Tick();
				MouseManager.Tick();
				glfwPollEvents();
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
