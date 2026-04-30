#include "Graphics/Buffer/Element.hpp"



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

Buffer::Element::Element(VertexArray & vertex_array, const Element & other)
	: Buffer::Base(vertex_array, other)
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
