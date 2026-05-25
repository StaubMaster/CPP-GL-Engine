#include "Instance/Basic3D/Buffer.hpp"
#include "Instance/Basic3D/Data.hpp"

#include "OpenGLTypes.hpp"



/*Instance::Basic3D::Buffer::~Buffer() { }
Instance::Basic3D::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StreamDraw)
{ }
Instance::Basic3D::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
{ }*/



Instance::Basic3D::Layout::~Layout() { }
Instance::Basic3D::Layout::Layout()
	: ::Attribute::Layout(1, sizeof(Basic3D::Data))
	, Trans(*this)
	, Normal(*this)
{ }
Instance::Basic3D::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Trans(*this, other.Trans)
	, Normal(*this, other.Normal)
{ }
