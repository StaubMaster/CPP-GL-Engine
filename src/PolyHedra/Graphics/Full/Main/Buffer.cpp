#include "PolyHedra/Graphics/Full/Main/Buffer.hpp"
#include "PolyHedra/Graphics/Full/Main/Data.hpp"

#include "OpenGLTypes.hpp"



PolyHedraFull::Main::Buffer::~Buffer() { }
PolyHedraFull::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(Main::Data))
	, Position(*this)
	, Normal(*this)
	, Texture(*this)
{ }
PolyHedraFull::Main::Buffer::Buffer(VertexArray & vertex_array, const Buffer & other)
	: ::Buffer::Array(vertex_array, other)
	, Position(*this, other.Position)
	, Normal(*this, other.Normal)
	, Texture(*this, other.Texture)
{ }
