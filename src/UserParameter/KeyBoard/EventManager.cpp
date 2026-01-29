#include "UserParameter/KeyBoard/EventManager.hpp"
#include "UserParameter/KeyBoardInclude.hpp"

#include "Window.hpp"
#include <GLFW/glfw3.h>



UserParameter::KeyBoard::EventManager::EventManager(Window & win, unsigned int count) :
	window(win),
	Keys(count),
	KeyCallBack(),
	TextCallBack()
{ }
UserParameter::KeyBoard::EventManager::~EventManager()
{ }



void UserParameter::KeyBoard::EventManager::Tick()
{
	Keys.Tick();
}
void UserParameter::KeyBoard::EventManager::UpdateKey(int key, int scancode, int action, int mods)
{
	if (Keys.Has(key))
	{
		UserParameter::Haptic::State & state = Keys[key];
		state.Update(UserParameter::Haptic::Action(action));
	}

	KeyCallBack(UserParameter::KeyBoard::Key(key, scancode, action, mods));
}
void UserParameter::KeyBoard::EventManager::UpdateText(unsigned int codepoint)
{
	TextCallBack(UserParameter::KeyBoard::Text(codepoint));
}