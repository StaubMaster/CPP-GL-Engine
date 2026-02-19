#include "InstanceData/Simple3D/Buffer.hpp"
#include "InstanceData/Simple3D/Data.hpp"



Simple3D::Buffer::Buffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot
) :
	::Buffer::Attribute(GL::BufferTarget::ArrayBuffer, GL::BufferDataUsage::StreamDraw, 1, sizeof(Simple3D::Data)),
	Trans(*this, indexTransPos, indexTransRot)
{
	Attributes.Allocate(1);
	Attributes.Insert(&Trans);
}
Simple3D::Buffer::~Buffer()
{ }

Simple3D::Buffer::Buffer(const Buffer & other) :
	::Buffer::Attribute(other),
	Trans(other.Trans)
{ }
Simple3D::Buffer & Simple3D::Buffer::operator=(const Buffer & other)
{
	::Buffer::Attribute::operator=(other);
	Trans = other.Trans;
	return *this;
}
