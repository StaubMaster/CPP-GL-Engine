#ifndef  WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"
# include "DataStruct/Point2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

# include "UserParameter/KeyBoard/KeyRange1.hpp"
# include "UserParameter/KeyBoard/KeyRange2.hpp"
# include "UserParameter/KeyBoard/Key.hpp"
# include "UserParameter/KeyBoard/Text.hpp"

# include "UserParameter/Mouse/ButtonRange.hpp"
# include "UserParameter/Mouse/Click.hpp"
# include "UserParameter/Mouse/Scroll.hpp"
# include "UserParameter/Mouse/EventManager.hpp"



struct GLFWwindow;

struct Point3D;
struct Angle3D;

class Window
{
	private:
	public:
	GLFWwindow * win;
	UserParameter::KeyBoard::KeyRange2 Keys;
	UserParameter::Mouse::EventManager MouseManager;

	public:
	bool ShowFrameData;
	private:
	double FrameTimeLast;
	double FrameTimeDelta;

	public:
	void (*InitFunc)();
	void (*FrameFunc)(double);
	void (*FreeFunc)();

	void (*ResizeFunc)(const SizeRatio2D &);

	void (*KeyFunc)		(UserParameter::KeyBoard::Key);
	void (*TextFunc)	(UserParameter::KeyBoard::Text);

	public:
	SizeRatio2D ViewPortSizeRatio;
	private:
	Point2D Center;
	public:
	Color DefaultColor;

	public:
	Window(float w, float h);	//	why does this take float ?
	~Window();

	private:
	static void Callback_Error(int error, const char * decription);

	private:
	static void Callback_Resize(GLFWwindow * window, int w, int h);
	static void Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods);
	static void Callback_Text(GLFWwindow * window, unsigned int codepoint);

	//	Put these into MouseEventManager
	static void Callback_Cursor(GLFWwindow * window, double xPos, double yPos);
	static void Callback_Click(GLFWwindow * window, int button, int action, int mods);
	static void Callback_Scroll(GLFWwindow * window, double xOffset, double yOffset);

	private:
	void Callback_Resize(int w, int h);
	void Callback_Key(int key, int scancode, int action, int mods);
	void Callback_Text(unsigned int codepoint);

	//	Put these into MouseEventManager
	void Callback_Cursor(double xPos, double yPos);
	void Callback_Click(int button, int action, int mods);
	void Callback_Scroll(double xOffset, double yOffset);

	public:
	void ChangeCallbackClick(void (*func)(UserParameter::Mouse::Click));
	void ChangeCallbackScroll(void (*func)(UserParameter::Mouse::Scroll));

	public:
	Point3D MoveFromKeys(float speed) const;
	Angle3D SpinFromCursor(float speed) const;

	public:
	void Run();
	void Term();
};

#endif