#include "PolyHedra/Graphics/Wire/Main/Buffer.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"
#include "OpenGL.hpp"



PolyHedraWire::Main::Buffer::~Buffer() { }
PolyHedraWire::Main::Buffer::Buffer(BufferArray::Base & buffer_array)
	: ::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(PolyHedraWire::Main::Data))
	, Pos()
	, Col()
{
	Attributes.Allocate(2);
	Attributes.Insert(&Pos);
	Attributes.Insert(&Col);
}
