#include "Graphics/Attribute/Base/Location.hpp"

#include "Debug.hpp"
#include <sstream>
#include "OpenGL.hpp"

void Attribute::Location::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Attribute::Location:" << " Type: " << Type << " Size0: " << Size0 << " Size1: " << Size1 << " Offset: " << Offset;
	Debug::Log << " Index:";
	for (unsigned int s = 0; s < Size1; s++)
	{
		Debug::Log << " " << (Index + s);
	}
	Debug::Log << '\n';
}
