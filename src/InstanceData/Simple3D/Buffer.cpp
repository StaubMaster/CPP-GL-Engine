#include "InstanceData/Simple3D/Buffer.hpp"
#include "InstanceData/Simple3D/Data.hpp"



Simple3D::Buffer::~Buffer() { }

Simple3D::Buffer::Buffer(BufferArray::Base & buffer_array)
	: ::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Simple3D::Data))
//	, Trans()
	, Point()
{
	Attributes.Allocate(1);
//	Attributes.Insert(&Trans);
	Attributes.Insert(&Point);
}

Simple3D::Buffer::Buffer(const Buffer & other) :
	::Buffer::Attribute(other),
//	Trans(other.Trans)
	Point(other.Point)
{ }
Simple3D::Buffer & Simple3D::Buffer::operator=(const Buffer & other)
{
	::Buffer::Attribute::operator=(other);
//	Trans = other.Trans;
	Point = other.Point;
	return *this;
}
