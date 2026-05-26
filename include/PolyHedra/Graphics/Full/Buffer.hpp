#ifndef  POLYHEDRA_GRAPHICS_FULL_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_FULL_BUFFER_HPP

# include "Graphics/Buffer/MainInst.hpp"

namespace PolyHedraFull
{
typedef ::BufferArray::MainInst<
	GL::BufferDataUsage::StaticDraw,
	GL::BufferDataUsage::StreamDraw,
	GL::DrawMode::Triangles
> Buffer;
};

#endif