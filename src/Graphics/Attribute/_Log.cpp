#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>

#include "Graphics/Attribute/Base/Base.hpp"
#include "Graphics/Attribute/Base/FloatNBase.hpp"
#include "Graphics/Attribute/Base/UIntNBase.hpp"



void Attribute::Base::LogInfo() const { }

void Attribute::FloatNBase::LogInfoBase(GL::AttributeType type, unsigned int size0, unsigned int size1) const
{
	//Debug::Log << Debug::Tabs << "Attribute::Location:" << " Type: " << GL::AttributeType::Float << " Size0: " << Size0 << " Size1: " << Size1 << " Offset: " << (Size0 * sizeof(float));
	Debug::Log << Debug::Tabs;
	Debug::Log << type << '*' << size0 << '*' << size1;
	//Debug::Log << (Size0 * sizeof(float));
	//Debug::Log << " Index:";
	for (unsigned int s = 0; s < size1; s++)
	{
		Debug::Log << ':' << (Index + s);
	}
	Debug::Log << '\n';
}
void Attribute::UIntNBase::LogInfoBase(GL::AttributeIntType type, unsigned int size0, unsigned int size1) const
{
	//Debug::Log << Debug::Tabs << "Attribute::Location:" << " Type: " << GL::AttributeType::Float << " Size0: " << Size0 << " Size1: " << Size1 << " Offset: " << (Size0 * sizeof(float));
	Debug::Log << Debug::Tabs;
	Debug::Log << type << '*' << size0 << '*' << size1;
	//Debug::Log << (Size0 * sizeof(float));
	//Debug::Log << " Index:";
	for (unsigned int s = 0; s < size1; s++)
	{
		Debug::Log << ':' << (Index + s);
	}
	Debug::Log << '\n';
}
