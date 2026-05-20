#include "Graphics/Buffer/Array.hpp"



Buffer::Array::~Array()
{ }
Buffer::Array::Array(VertexArray & vertex_array, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, GL::AttributeStride stride)
	: Buffer::Base(vertex_array, GL::BufferTarget::ArrayBuffer, usage)
	, Divisor(divisor)
	, Stride(stride)
	, Count(0)
	, AttributesBound(false)
	, Attributes()
{ }
Buffer::Array::Array(VertexArray & vertex_array, const Array & other)
	: Buffer::Base(vertex_array, other)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
	, Count(other.Count)
	, AttributesBound(other.AttributesBound)
	, Attributes(other.Attributes)
{ }
Buffer::Array & Buffer::Array::operator=(const Array & other)
{
	Base::operator=(other);
	Divisor = other.Divisor;
	Stride = other.Stride;
	Count = other.Count;
	AttributesBound = other.AttributesBound;
	return *this;
}



void Buffer::Array::Update()
{
	Bind();
	if (!AttributesBound)
	{
		GL::AttributeOffset offset = nullptr;
		for (unsigned int i = 0; i < Attributes.Count(); i++)
		{
			Attributes[i] -> Bind(Divisor, Stride, offset);
		}
		AttributesBound = true;
	}
}
void Buffer::Array::NewSize(unsigned int size)
{
	Count = size / Stride;
}
