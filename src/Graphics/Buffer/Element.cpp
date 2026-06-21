#include "Graphics/Buffer/Element.hpp"



Buffer::Element::~Element() { }
Buffer::Element::Element(GL::BufferDataUsage usage, GL::DrawIndexType index_type)
	: Buffer::Base(GL::BufferTarget::ElementArrayBuffer, usage)
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



void Buffer::Element::NewSize(unsigned int size)
{
	Count = size / IndexSize;
}
