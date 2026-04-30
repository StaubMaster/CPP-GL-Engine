#include "PolyGon/Graphics/Full/Main/Buffer.hpp"
#include "PolyGon/Graphics/Full/Main/Data.hpp"

#include "OpenGLTypes.hpp"



PolyGonFull::Main::Buffer::~Buffer() { }
PolyGonFull::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(Main::Data))
	, Pos(*this)
	, Col(*this)
{ }
PolyGonFull::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
	, Pos(*this, other.Pos)
	, Col(*this, other.Col)
{ }
