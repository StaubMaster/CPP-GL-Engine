#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/Base.hpp"

#include "Debug.hpp"
#include <sstream>



void Uniform::FloatN::LogInfo(bool self) const
{
	Location.LogInfo(self);
	/*if (self)
	{
		Debug::Log << Debug::Tabs << "FloatN Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << '"' << (Name) << '"' << ':' << Location << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}*/
}



Uniform::FloatN::FloatN(::Shader::Base & shader, std::string name, unsigned int size0, unsigned int size1, int count)
	: Base(shader, name)
	, Location(shader, name, size0, size1, count)
//	, Location(Locate())
//	, Count(count)
{
	Location.Change(Locate());
}



void Uniform::FloatN::ReLocate()
{
	Location.Change(Locate());
}
void Uniform::FloatN::PutVoid(const void * val)
{
	if (!Shader.IsBound())
	{
		Shader.Bind();
	}
	//PutData((const float *)val);
	Location.PutVoid(val);
}
