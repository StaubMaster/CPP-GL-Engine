#include "Graphics/Attribute/Base/Base.hpp"
#include "Graphics/Attribute/Base/FloatN.hpp"

#include "Debug.hpp"
#include <sstream>
#include "OpenGL.hpp"

/*template<unsigned int Size0, unsigned int Size1>
void Attribute::FloatN<Size0, Size1>::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Attribute::Location:" << " Type: " << Type << " Size0: " << Size0 << " Size1: " << Size1 << " Offset: " << Offset;
	Debug::Log << " Index:";
	for (unsigned int s = 0; s < Size1; s++)
	{
		Debug::Log << " " << (Index + s);
	}
	Debug::Log << '\n';
}*/

void Attribute::Base::LogInfo() const { }
