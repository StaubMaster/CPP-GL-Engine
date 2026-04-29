#include "PolyHedra/Graphics/Full/Main/Buffer.hpp"
#include "PolyHedra/Graphics/Full/Main/Data.hpp"

#include "OpenGLTypes.hpp"



PolyHedraFull::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(Main::Data))
	, Position()
	, Normal()
	, Texture()
{
	Attributes.Allocate(3);
	Attributes.Insert(&Position);
	Attributes.Insert(&Normal);
	Attributes.Insert(&Texture);
}
