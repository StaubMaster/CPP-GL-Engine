#include "PolyGon/Graphics/Full/Main/Buffer.hpp"
#include "PolyGon/Graphics/Full/Main/Data.hpp"

#include "OpenGLTypes.hpp"



PolyGonFull::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(Main::Data))
	, Pos()
	, Col()
{
	Attributes.Allocate(2);
	Attributes.Insert(&Pos);
	Attributes.Insert(&Col);
}
