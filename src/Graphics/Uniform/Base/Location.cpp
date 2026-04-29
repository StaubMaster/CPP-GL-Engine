#include "Graphics/Uniform/Base/Location.hpp"


#include "Debug.hpp"
#include <sstream>



void Uniform::Location::LogInfo(bool self) const
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



Uniform::Location::~Location() { }

Uniform::Location::Location(::Shader::Base & shader, std::string name,
	unsigned int size0,
	unsigned int size1,
	unsigned int count
)
	: Shader(shader)
	, Name(name)
	, Size0(size0)
	, Size1(size1)
	, Count(count)
	, Index(-1)
{ }



void Uniform::Location::Change(GL::UniformLocation index)
{
	Index = index;
}
