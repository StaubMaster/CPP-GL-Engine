#include "PolyGon/Graphics/Wire/Main/Buffer.hpp"
#include "PolyGon/PolyGon.hpp"
#include "OpenGL.hpp"



PolyGonWire::Main::Buffer::~Buffer() { }
PolyGonWire::Main::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Array(vertex_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(PolyGon::Corner))
	, Pos()
	, Col()
{
	Attributes.Allocate(2);
	Attributes.Insert(&Pos);
	Attributes.Insert(&Col);
}
