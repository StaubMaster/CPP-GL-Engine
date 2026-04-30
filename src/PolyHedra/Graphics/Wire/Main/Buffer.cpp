#include "PolyHedra/Graphics/Wire/Main/Buffer.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"
#include "OpenGL.hpp"



PolyHedraWire::Main::Buffer::~Buffer() { }
PolyHedraWire::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(PolyHedraWire::Main::Data))
	, Pos(*this)
	, Col(*this)
{ }
PolyHedraWire::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
	, Pos(*this, other.Pos)
	, Col(*this, other.Col)
{ }
