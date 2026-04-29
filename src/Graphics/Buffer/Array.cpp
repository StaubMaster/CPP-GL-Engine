#include "Graphics/Buffer/Array.hpp"



Buffer::Array::~Array()
{ }
Buffer::Array::Array(VertexArray & vertex_array, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, GL::AttributeStride stride)
	: Buffer::Base(vertex_array, GL::BufferTarget::ArrayBuffer, usage)
	, Divisor(divisor)
	, Stride(stride)
	, Count(0)
	, Attributes()
{ }
Buffer::Array::Array(const Array & other)
	: Buffer::Base(other)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
	, Count(other.Count)
	, Attributes(other.Attributes)
{ }
Buffer::Array & Buffer::Array::operator=(const Array & other)
{
	Base::operator=(other);
	Divisor = other.Divisor;
	Stride = other.Stride;
	Count = other.Count;
	return *this;
}



void Buffer::Array::Init()
{
	Base::Data();
	GL::AttributeOffset offset = nullptr;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(Divisor, Stride, offset);
	}
}
void Buffer::Array::Data(const Container::Void & data)
{
	Base::Data(data);
	Count = data.VoidCount() / Stride;
}
