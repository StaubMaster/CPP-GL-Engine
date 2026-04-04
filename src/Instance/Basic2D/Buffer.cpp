#include "Instance/Basic2D/Buffer.hpp"
#include "Instance/Basic2D/Data.hpp"

#include "OpenGLTypes.hpp"



Instance::Basic2D::Buffer::~Buffer() { }

Instance::Basic2D::Buffer::Buffer(BufferArray::Base & buffer_array)
	: ::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Data))
	, Trans()
{
	Attributes.Allocate(1);
	Attributes.Insert(&Trans);
}
