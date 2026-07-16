#ifndef  POLYHEDRA_GRAPHICS_ELEM_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_ELEM_BUFFER_HPP

# include "Graphics/VertexArray/MainElemInst.hpp"

namespace PolyHedraWire
{
typedef ::VertexArray::MainElemInst Buffer;
/*typedef ::VertexArray::MainElemInst<
	GL::BufferDataUsage::StaticDraw,
	GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt,
	GL::BufferDataUsage::StreamDraw,
	GL::DrawMode::Lines
> Buffer;*/
};

#endif