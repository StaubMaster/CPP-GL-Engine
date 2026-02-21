#include "Debug.hpp"
#include <sstream>
#include "OpenGL.hpp"

#include "Graphics/Attribute/Base/Location.hpp"

#include "Graphics/Attribute/Base/Float1.hpp"
#include "Graphics/Attribute/Base/Float2.hpp"
#include "Graphics/Attribute/Base/Float3.hpp"
#include "Graphics/Attribute/Base/Float4.hpp"
#include "Graphics/Attribute/Base/Float2x2.hpp"
#include "Graphics/Attribute/Base/Float3x3.hpp"

#include "Graphics/Attribute/Trans2D.hpp"
#include "Graphics/Attribute/Trans3D.hpp"



void Attribute::Location::LogInfo() const
{
	Debug::Log << Debug::Tabs << "Attribute::Location:" << " Count: " << Count << " Type: " << Type << " Size: " << Size << " Index: " << Index << '\n';
}



void Attribute::Float1::LogInfo() const
{
//	Debug::Log << "Float1:\n";
//	Debug::Log << Debug::TabInc;
	Location.LogInfo();
//	Debug::Log << Debug::TabDec;
}
void Attribute::Float2::LogInfo() const
{
//	Debug::Log << "Float2:\n";
//	Debug::Log << Debug::TabInc;
	Location.LogInfo();
//	Debug::Log << Debug::TabDec;
}
void Attribute::Float3::LogInfo() const
{
//	Debug::Log << "Float3:\n";
//	Debug::Log << Debug::TabInc;
	Location.LogInfo();
//	Debug::Log << Debug::TabDec;
}
void Attribute::Float4::LogInfo() const
{
//	Debug::Log << "Float4:\n";
//	Debug::Log << Debug::TabInc;
	Location.LogInfo();
//	Debug::Log << Debug::TabDec;
}

void Attribute::Float2x2::LogInfo() const
{
//	Debug::Log << "Float2x2:\n";
//	Debug::Log << Debug::TabInc;
	Location0.LogInfo();
	Location1.LogInfo();
//	Debug::Log << Debug::TabDec;
}
void Attribute::Float3x3::LogInfo() const
{
//	Debug::Log << "Float3x3:\n";
//	Debug::Log << Debug::TabInc;
	Location0.LogInfo();
	Location1.LogInfo();
	Location2.LogInfo();
//	Debug::Log << Debug::TabDec;
}



void Attribute::Trans2D::LogInfo() const
{
//	Debug::Log << "Trans2D:" << '\n';
//	Debug::Log << Debug::TabInc;
//	Debug::Log << Debug::Tabs << "Pos:\n";
	Pos.LogInfo();
//	Debug::Log << Debug::Tabs << "Rot:\n";
	Rot.LogInfo();
//	Debug::Log << Debug::TabDec;
}
void Attribute::Trans3D::LogInfo() const
{
//	Debug::Log << "Trans3D:" << '\n';
//	Debug::Log << Debug::TabInc;
//	Debug::Log << Debug::Tabs << "Pos:\n";
	Pos.LogInfo();
//	Debug::Log << Debug::Tabs << "Rot:\n";
	Rot.LogInfo();
//	Debug::Log << Debug::TabDec;
}
