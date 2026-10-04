#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>

#include "Graphics/VertexArray/Base.hpp"

#include "Graphics/Attribute/General/Layout.hpp"



void VertexArray::Base::LogInfo() const
{
	Debug::Log << Debug::Tabs << "VertexArray::Base: ";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void VertexArray::Base::LogLine() const
{
	Debug::Log << "VertexArray::Base: ";
	Debug::Log << "{ ";
	Debug::Log << "ID: " << ID << ' ';
	Debug::Log << "}";
}
void VertexArray::Base::LogLine(const char * str) const
{
	Debug::Log << str << ' ';
	LogLine();
	Debug::Log << Debug::Done;
}
