#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/Base.hpp"

#include "Debug.hpp"
#include <sstream>



void Uniform::FloatN::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "FloatN Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << '"' << (Name) << '"' << ':' << Location << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Uniform::FloatN::FloatN(Uniform::NameShader name_shader, int count) : Base(name_shader),
	Location(Locate()),
	Count(count)
{ }



void Uniform::FloatN::ReLocate()
{
	Location = Locate();
}
void Uniform::FloatN::PutVoid(const void * val)
{
	PutData((const float *)val);
}
