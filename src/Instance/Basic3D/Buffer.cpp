#include "Instance/Basic3D/Buffer.hpp"
#include "Instance/Basic3D/Data.hpp"

#include "OpenGLTypes.hpp"



Instance::Basic3D::Buffer::~Buffer() { }

Instance::Basic3D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StreamDraw, 1, sizeof(Basic3D::Data))
	, Trans(*this)
	, Normal(*this)
{ }
