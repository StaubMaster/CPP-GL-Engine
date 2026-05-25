#include "Instance/Basic2D/Buffer.hpp"
#include "Instance/Basic2D/Data.hpp"

#include "OpenGLTypes.hpp"



/*Instance::Basic2D::Buffer::~Buffer() { }
Instance::Basic2D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StreamDraw)
{ }
Instance::Basic2D::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
{ }*/



Instance::Basic2D::Layout::~Layout() { }
Instance::Basic2D::Layout::Layout()
	: ::Attribute::Layout(1, sizeof(Basic2D::Data))
	, Trans(*this)
{ }
Instance::Basic2D::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Trans(*this, other.Trans)
{ }
