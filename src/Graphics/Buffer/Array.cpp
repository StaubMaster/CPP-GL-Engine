#include "Graphics/Buffer/Array.hpp"

#include "Graphics/Attribute/General/Layout.hpp"



Buffer::Array::~Array()
{ }
Buffer::Array::Array(GL::BufferDataUsage usage)
	: Buffer::Base(GL::BufferTarget::ArrayBuffer, usage)
	, Count(0)
	, AttributesBound(false)
	, AttributeLayout(nullptr)
{ }



void Buffer::Array::Init(Attribute::Layout & layout)
{
	AttributeLayout = &layout;
	AttributesBound = false;
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
