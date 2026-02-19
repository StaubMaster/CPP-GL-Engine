#include "InstanceData/Physics3D/Buffer.hpp"
#include "InstanceData/Physics3D/Data.hpp"



Physics3D::Buffer::Buffer(
	BufferArray::Base & buffer_array,
	unsigned int indexTransPos,
	unsigned int indexTransRot,
	unsigned int indexVelPos,
	unsigned int indexVelRot
) :	::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Physics3D::Data)),
	Trans(*this, indexTransPos, indexTransRot),
	Vel(*this, indexVelPos, indexVelRot)
{
	Attributes.Allocate(2);
	Attributes.Insert(&Trans);
	Attributes.Insert(&Vel);
}
Physics3D::Buffer::~Buffer()
{ }
