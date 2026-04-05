#include "PolyHedra/Graphics/Wire/Elem/Buffer.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "OpenGL.hpp"



PolyHedraWire::Elem::Buffer::~Buffer() { }
PolyHedraWire::Elem::Buffer::Buffer(BufferArray::Base & buffer_array, unsigned int elem_per_type)
	: ::Buffer::Element(buffer_array, GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt, elem_per_type)
{ }
