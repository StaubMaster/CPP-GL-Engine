#include "Graphics/Buffer/Array.hpp"
#include "OpenGLEnums.hpp"

#include "Graphics/Attribute/General/Layout.hpp"



Buffer::Array::~Array()
{ }
Buffer::Array::Array(GL::BufferDataUsage usage)
	: Buffer::Base(GL::BufferTarget::ArrayBuffer, usage)
{ }



void Buffer::Array::Init()
{
	Bind();
	if (Layout != nullptr)
	{
		Layout -> Bind();
	}
}
