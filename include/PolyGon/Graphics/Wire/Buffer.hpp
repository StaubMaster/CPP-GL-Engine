#ifndef  POLYGON_GRAPHICS_WIRE_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_BUFFER_HPP

# include "Graphics/Buffer/MainElemInst.hpp"

namespace PolyGonWire
{
typedef ::BufferArray::MainElemInst<
	GL::BufferDataUsage::StaticDraw,
	GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt,
	GL::BufferDataUsage::StaticDraw,
	GL::DrawMode::Lines
> Buffer;
};

#endif