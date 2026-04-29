#include "PolyGon/Graphics/Wire/Elem/Buffer.hpp"
#include "PolyGon/PolyGon.hpp"
#include "OpenGL.hpp"



PolyGonWire::Elem::Buffer::~Buffer() { }
PolyGonWire::Elem::Buffer::Buffer(VertexArray & vertex_array)
	: ::Buffer::Element(vertex_array, GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt)
{ }
