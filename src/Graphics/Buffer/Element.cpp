#include "Graphics/Buffer/Element.hpp"
#include "OpenGL.hpp"

//#include "OpenGL/Errors.hpp"
#include "Debug.hpp"
#include <sstream>
//#include <iostream>



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



Buffer::Element::~Element() { }
Buffer::Element::Element(VertexArray & vertex_array, GL::BufferDataUsage usage, GL::DrawIndexType index_type)
	: Buffer::Base(vertex_array, GL::BufferTarget::ElementArrayBuffer, usage)
	, IndexType(index_type)
	, IndexSize(0)
	, Count(0)
{
	switch (index_type)
	{
		case GL::DrawIndexType::UnsignedByte: IndexSize = 1; break;
		case GL::DrawIndexType::UnsignedShort: IndexSize = 2; break;
		case GL::DrawIndexType::UnsignedInt: IndexSize = 4; break;
	}
}

Buffer::Element::Element(const Element & other)
	: Buffer::Base(other)
	, IndexType(other.IndexType)
	, IndexSize(other.IndexSize)
	, Count(other.Count)
{ }
Buffer::Element & Buffer::Element::operator=(const Element & other)
{
	Base::operator=(other);
	IndexType = other.IndexType;
	IndexSize = other.IndexSize;
	Count = other.Count;
	return *this;
}



void Buffer::Element::Data(const Container::Void & data)
{
	Base::Data(data);
	Count = data.VoidCount() / IndexSize;
}
