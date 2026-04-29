#include "InstanceData/Physics3D/Buffer.hpp"
#include "InstanceData/Physics3D/Data.hpp"



Physics3D::Buffer::~Buffer() { }

Physics3D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(buffer_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Physics3D::Data))
	, Trans()
	, Vel()
{
	Attributes.Allocate(2);
	Attributes.Insert(&Trans);
	Attributes.Insert(&Vel);
}
