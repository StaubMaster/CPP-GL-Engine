#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>

#include "Graphics/Uniform/Base/Base.hpp"
#include "Graphics/Uniform/Base/FloatNBase.hpp"



void Uniform::Base::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Uniform Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << '"' << (Name) << '"' << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}

void Uniform::FloatNBase::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Uniform Location Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << '"' << (Name) << '"' << ':' << Index << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}
