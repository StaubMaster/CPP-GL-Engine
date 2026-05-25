#ifndef  POLYGON_GRAPHICS_WIRE_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_BUFFER_HPP

# include "Graphics/Buffer/MainElemInst.hpp"
# include "Graphics/Buffer/Array.hpp"

# include "PolyGon/Graphics/Wire/Main/Buffer.hpp"
# include "PolyGon/Graphics/Wire/Elem/Buffer.hpp"
# include "Instance/Basic2D/Buffer.hpp"

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