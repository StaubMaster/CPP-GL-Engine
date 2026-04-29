#include "Graphics/Buffer/Base.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Buffer/Element.hpp"
#include "Graphics/Buffer/VertexArray.hpp"

#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>
#include <iostream>



void Buffer::Base::LogInfo(bool self) const
{
	(void)self;
	//if (self)
	//{
	//	Debug::Log << Debug::Tabs << "Buffer Info\n";
	//	Debug::Log << Debug::TabInc;
	//}
	//Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	//if (self)
	//{
	//	Debug::Log << Debug::TabDec;
	//	Debug::Log << Debug::Done;
	//}
}

void Buffer::Array::LogInfo(bool self) const
{
	(void)self;
	//Debug::Log << Debug::Tabs << "Buffer::Array\n";
	//Debug::Log << Debug::TabInc;
	//Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	//Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	//Debug::Log << Debug::Tabs << "Divisor: " << Divisor << '\n';
	//Debug::Log << Debug::Tabs << "Stride: " << Stride << '\n';
	//for (unsigned int i = 0; i < Attributes.Count(); i++)
	//{
	//	Attributes[i] -> LogInfo();
	//}
	//Debug::Log << Debug::TabDec;
}

void Buffer::Element::LogInfo(bool self) const
{
	(void)self;
	//Debug::Log << Debug::Tabs << "Buffer::Element\n";
	//Debug::Log << Debug::TabInc;
	//Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	//Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	//Debug::Log << Debug::Tabs << "IndexType: " << IndexType << '\n';
	//Debug::Log << Debug::TabDec;
}

void VertexArray::LogInfo(bool self) const
{
	(void)self;
	//if (self)
	//{
	//	Debug::Log << Debug::Tabs << "Buffer Array Info\n";
	//	Debug::Log << Debug::TabInc;
	//}
	//Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	//Debug::Log << Debug::Tabs << "Buffers[" << Buffers.Count() << "]\n";
	//Debug::Log << Debug::TabInc;
	//for (unsigned int i = 0; i < Buffers.Count(); i++)
	//{
	//	Buffers[i] -> LogInfo(false);
	//}
	//Debug::Log << Debug::TabDec;
	//if (self)
	//{
	//	Debug::Log << Debug::TabDec;
	//	Debug::Log << Debug::Done;
	//}
}
