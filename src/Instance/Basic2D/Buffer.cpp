#include "Instance/Basic2D/Buffer.hpp"
#include "Instance/Basic2D/Data.hpp"

#include "OpenGLTypes.hpp"



Instance::Basic2D::Buffer::~Buffer() { }

Instance::Basic2D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Basic2D::Data))
	, Trans(*this)
{ }
