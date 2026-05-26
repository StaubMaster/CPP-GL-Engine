#ifndef  POLYHEDRA_GRAPHICS_ELEM_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_ELEM_BUFFER_HPP

# include "Graphics/Buffer/MainElemInst.hpp"

namespace PolyHedraWire
{
typedef ::BufferArray::MainElemInst<
	GL::BufferDataUsage::StaticDraw,
	GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt,
	GL::BufferDataUsage::StreamDraw,
	GL::DrawMode::Lines
> Buffer;
};

#endif