#include "PolyGon/Graphics/Wire/Main/Buffer.hpp"
#include "PolyGon/PolyGon.hpp"

#include "OpenGLTypes.hpp"



/*PolyGonWire::Main::Buffer::~Buffer() { }
PolyGonWire::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw)
{ }
PolyGonWire::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
{ }*/



PolyGonWire::Main::Layout::~Layout() { }
PolyGonWire::Main::Layout::Layout()
	: ::Attribute::Layout(0, sizeof(PolyGon::Corner))
	, Pos(*this)
	, Col(*this)
{ }
PolyGonWire::Main::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Pos(*this, other.Pos)
	, Col(*this, other.Col)
{ }
