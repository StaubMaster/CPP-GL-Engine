#include "Debug.hpp"
#include "OpenGL.hpp"
#include <sstream>

#include "Graphics/Texture/Base.hpp"



void Texture::Base::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Texture::Base\n";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Target: " << Target << '\n';
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void Texture::Base::LogLine() const
{
	Debug::Log << "Texture::Base ";
	Debug::Log << "{ ";
	Debug::Log << "ID: " << ID << ' ';
	Debug::Log << "Target: " << Target << ' ';
	Debug::Log << "}";
}
void Texture::Base::LogLine(const char * str) const
{
	Debug::Log << str << ' ';
	LogLine();
	Debug::Log << Debug::Done;
}
