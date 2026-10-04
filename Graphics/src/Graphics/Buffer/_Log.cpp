#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>

#include "Graphics/Buffer/Base.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Buffer/Element.hpp"
#include "Graphics/Buffer/Uniform.hpp"

#include "Graphics/Attribute/General/Layout.hpp"



void Buffer::Base::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Buffer::Base\n";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void Buffer::Base::LogLine() const
{
	Debug::Log << "Buffer::Base" << ' ';
	Debug::Log << "{" << ' ';
	Debug::Log << "ID " << ID << ' ';
	Debug::Log << "}";
}
void Buffer::Base::LogLine(const char * str) const
{
	Debug::Log << str << ' ';
	LogLine();
	Debug::Log << Debug::Done;
}

void Buffer::Array::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Buffer::Array\n";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	/*if (AttributeLayout != nullptr)
	{
		AttributeLayout -> LogInfo();
	}
	else
	{
		Debug::Log << Debug::Tabs << "Missing Layout\n";
	}*/
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void Buffer::Array::LogLine() const
{
	Debug::Log << "Buffer::Array ";
	Debug::Log << "{ ";
	Debug::Log << "ID: " << ID << ' ';
	Debug::Log << "Usade: " << Usage << ' ';
	Debug::Log << "Layout: ";
	if (Layout != nullptr)
	{
		Layout -> LogLine();
	}
	else
	{
		Debug::Log << "Missing";
	}
	Debug::Log << ' ';
	Debug::Log << "}";
}

void Buffer::Element::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Buffer::Element\n";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	Debug::Log << Debug::Tabs << "IndexType: " << IndexType << '\n';
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void Buffer::Element::LogLine() const
{
	Debug::Log << "Buffer::Element ";
	Debug::Log << "{ ";
	Debug::Log << "ID: " << ID << ' ';
	Debug::Log << "Usade: " << Usage << ' ';
	Debug::Log << "IndexType: " << IndexType << ' ';
	Debug::Log << "}";
}

void Buffer::Uniform::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Buffer::Uniform\n";
	Debug::Log << Debug::Tabs << "{\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	Debug::Log << Debug::TabDec;
	Debug::Log << Debug::Tabs << "}\n";
	Debug::Log << Debug::Done;
}
void Buffer::Uniform::LogLine() const
{
	Debug::Log << "Buffer::Uniform ";
	Debug::Log << "{ ";
	Debug::Log << "ID: " << ID << ' ';
	Debug::Log << "Usade: " << Usage << ' ';
	Debug::Log << "}";
}
