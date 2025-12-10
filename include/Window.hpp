#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"
# include "DataStruct/Point2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

# include "UserParameter/KeyBoard/KeyRange1.hpp"
# include "UserParameter/KeyBoard/KeyRange2.hpp"

# include "UserParameter/Click.hpp"
# include "UserParameter/Scroll.hpp"
# include "UserParameter/Key.hpp"
# include "UserParameter/Text.hpp"

//# include "Keys.hpp"

/*	UserParameters
make "Wrapper" for action
*/

struct GLFWwindow;

struct Point3D;
struct Angle3D;

class Window
{
	private:
	public:
		GLFWwindow * win;
		UserParameter::KeyBoard::KeyRange2 Keys;
		UserParameter::KeyBoard::KeyRange1 MouseButtons;

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

		void (*ClickFunc)	(UserParameter::Click);
		void (*ScrollFunc)	(UserParameter::Scroll);
		void (*KeyFunc)		(UserParameter::Key);
		void (*TextFunc)	(UserParameter::Text);

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
		static void Callback_Click(GLFWwindow * window, int button, int action, int mods);
		static void Callback_Scroll(GLFWwindow * window, double xOffset, double yOffset);
	private:
		void Callback_Resize(int w, int h);
		void Callback_Key(int key, int scancode, int action, int mods);
		void Callback_Text(unsigned int codepoint);
		void Callback_Click(int button, int action, int mods);
		void Callback_Scroll(double xOffset, double yOffset);

	public:
		bool IsCursorLocked() const;
		void ToggleCursorLock();
		Point3D MoveFromKeys(float speed) const;
		Angle3D SpinFromCursor(float speed) const;
		Point2D CursorCentered() const;
		Point2D CursorPixel() const;

	public:
		void Run();
		void Term();
};

#endif