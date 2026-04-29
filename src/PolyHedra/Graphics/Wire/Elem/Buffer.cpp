#include "PolyHedra/Graphics/Wire/Elem/Buffer.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "OpenGL.hpp"



PolyHedraWire::Elem::Buffer::~Buffer() { }
PolyHedraWire::Elem::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Element(vertex_array, GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt)
{ }
