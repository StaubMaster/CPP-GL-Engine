#include "InstanceData/Simple3D/Simple3D_InstBuffer.hpp"
#include "InstanceData/Simple3D/Simple3D_InstData.hpp"



Simple3D_InstBuffer::Simple3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot
) :
	Buffer::Attribute(GL_ARRAY_BUFFER, GL_STREAM_DRAW, sizeof(Simple3D_InstData)),
	Trans(1, sizeof(Simple3D_InstData), indexTransPos, indexTransRot)
{
	Attributes.Allocate(1);
	Attributes.Insert(&Trans);
}
Simple3D_InstBuffer::~Simple3D_InstBuffer()
{ }

Simple3D_InstBuffer::Simple3D_InstBuffer(const Simple3D_InstBuffer & other) :
	Buffer::Attribute(other),
	Trans(other.Trans)
{ }
Simple3D_InstBuffer & Simple3D_InstBuffer::operator=(const Simple3D_InstBuffer & other)
{
	Buffer::Attribute::operator=(other);
	Trans = other.Trans;
	return *this;
}
