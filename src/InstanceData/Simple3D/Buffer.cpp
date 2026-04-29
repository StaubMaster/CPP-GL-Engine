#include "InstanceData/Simple3D/Buffer.hpp"
#include "InstanceData/Simple3D/Data.hpp"



Simple3D::Buffer::~Buffer() { }

Simple3D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Simple3D::Data))
	, Trans()
{
	Attributes.Allocate(1);
	Attributes.Insert(&Trans);
}

Simple3D::Buffer::Buffer(const Buffer & other) :
	::Buffer::Array(other),
	Trans(other.Trans)
{ }
Simple3D::Buffer & Simple3D::Buffer::operator=(const Buffer & other)
{
	::Buffer::Array::operator=(other);
	Trans = other.Trans;
	return *this;
}
