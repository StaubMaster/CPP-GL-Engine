#include "PolyHedra/Graphics/Full/Main/Buffer.hpp"
#include "PolyHedra/Graphics/Full/Main/Data.hpp"

#include "OpenGLTypes.hpp"



/*PolyHedraFull::Main::Buffer::~Buffer() { }
PolyHedraFull::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw)
{ }
PolyHedraFull::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
{ }*/



PolyHedraFull::Main::Layout::~Layout() { }
PolyHedraFull::Main::Layout::Layout()
	: ::Attribute::Layout(0, sizeof(Main::Data))
	, Position(*this)
	, Normal(*this)
	, Texture(*this)
{ }
PolyHedraFull::Main::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Position(*this, other.Position)
	, Normal(*this, other.Normal)
	, Texture(*this, other.Texture)
{ }
