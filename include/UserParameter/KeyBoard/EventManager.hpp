#ifndef  USER_PARAMETER_KEY_EVENNTMANAGER_HPP
# define USER_PARAMETER_KEY_EVENNTMANAGER_HPP

# include "UserParameter/KeyBoard/KeyRange1.hpp"
# include "UserParameter/KeyBoard/KeyRange2.hpp"
# include "UserParameter/KeyBoardDeclare.hpp"

# include "Function/Pointer.hpp"

class Window;

namespace UserParameter
{

namespace KeyBoard
{

class EventManager
{
	private:
	Window & window;

	public:
	UserParameter::KeyBoard::KeyRange2 Keys;

	public:
	FunctionPointer<UserParameter::KeyBoard::Key>	KeyCallBack;
	FunctionPointer<UserParameter::KeyBoard::Text>	TextCallBack;

	public:
	EventManager(Window & win, unsigned int count);
	~EventManager();
	EventManager(const EventManager & other) = delete;
	EventManager & operator=(const EventManager & other) = delete;

	public:
	void Tick();
	void UpdateKey(int key, int scancode, int action, int mods);
	void UpdateText(unsigned int codepoint);
};

};

};

#endif