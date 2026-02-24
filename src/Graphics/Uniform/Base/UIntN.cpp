#include "Graphics/Uniform/Base/UIntN.hpp"
#include "Graphics/Shader/Base.hpp"

#include "Debug.hpp"
#include <sstream>



void Uniform::UIntN::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "UIntN Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << '"' << (Name) << '"' << ':' << Location << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Uniform::UIntN::UIntN(::Shader::Base & shader, std::string name, int count)
	: Base(shader, name)
	, Location(Locate())
	, Count(count)
{ }



void Uniform::UIntN::ReLocate()
{
	Location = Locate();
}
void Uniform::UIntN::PutVoid(const void * val)
{
	if (!Shader.IsBound())
	{
		Shader.Bind();
	}
	PutData((const unsigned int *)val);
}
