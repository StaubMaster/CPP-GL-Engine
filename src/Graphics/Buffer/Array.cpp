#include "Graphics/Buffer/Array.hpp"

#include "Graphics/Attribute/Layout.hpp"



Buffer::Array::~Array()
{ }
Buffer::Array::Array(VertexArray & vertex_array, GL::BufferDataUsage usage)
	: Buffer::Base(vertex_array, GL::BufferTarget::ArrayBuffer, usage)
	, Count(0)
	, AttributesBound(false)
	, AttributeLayout(nullptr)
{ }
Buffer::Array::Array(VertexArray & vertex_array, const Array & other)
	: Buffer::Base(vertex_array, other)
	, Count(other.Count)
	, AttributesBound(other.AttributesBound)
	, AttributeLayout(other.AttributeLayout)
{ }
Buffer::Array & Buffer::Array::operator=(const Array & other)
{
	Base::operator=(other);
	Count = other.Count;
	AttributesBound = other.AttributesBound;
	AttributeLayout = other.AttributeLayout;
	return *this;
}



void Buffer::Array::Update()
{
	if (!AttributesBound)
	{
		Bind();
		if (AttributeLayout != nullptr)
		{
			AttributeLayout -> Bind();
			AttributesBound = true;
		}
	}
}
void Buffer::Array::NewSize(unsigned int size)
{
	if (AttributeLayout != nullptr)
	{
		Count = size / (AttributeLayout -> Stride);
	}
}
