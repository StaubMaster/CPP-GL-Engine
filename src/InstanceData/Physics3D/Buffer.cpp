#include "InstanceData/Physics3D/Buffer.hpp"
#include "InstanceData/Physics3D/Data.hpp"



Physics3D::Buffer::~Buffer() { }

Physics3D::Buffer::Buffer(BufferArray::Base & buffer_array)
	: ::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Physics3D::Data))
	, Trans()
	, Vel()
{
	Attributes.Allocate(2);
	Attributes.Insert(&Trans);
	Attributes.Insert(&Vel);
}
