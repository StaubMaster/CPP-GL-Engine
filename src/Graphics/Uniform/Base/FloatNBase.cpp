#include "Graphics/Uniform/Base/FloatNBase.hpp"
#include "Graphics/Shader/Base.hpp"

#include "Debug.hpp"
#include <sstream>



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



Uniform::FloatNBase::~FloatNBase() { }
Uniform::FloatNBase::FloatNBase(::Shader::Base & shader, std::string name)
	: Base(shader, name)
{ }



void Uniform::FloatNBase::PutVoid(const void * val)
{
	if (!Shader.IsBound())
	{
		Shader.Bind();
	}
	PutData((const float *)val);
}



void Uniform::FloatNBase::ReLocate()
{
	Index = Locate();
}
