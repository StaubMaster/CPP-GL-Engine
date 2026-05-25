#include "PolyHedra/Graphics/Wire/Main/Buffer.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"
#include "OpenGL.hpp"



/*PolyHedraWire::Main::Buffer::~Buffer() { }
PolyHedraWire::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw)
{ }
PolyHedraWire::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
{ }*/



PolyHedraWire::Main::Layout::~Layout() { }
PolyHedraWire::Main::Layout::Layout()
	: ::Attribute::Layout(0, sizeof(PolyHedraWire::Main::Data))
	, Pos(*this)
	, Col(*this)
{ }
PolyHedraWire::Main::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Pos(*this, other.Pos)
	, Col(*this, other.Col)
{ }
