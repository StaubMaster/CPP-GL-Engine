#ifndef  POLYHEDRA_GRAPHICS_FULL_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_FULL_BUFFER_HPP

# include "Graphics/VertexArray/MainInst.hpp"

namespace PolyHedraFull
{
typedef ::VertexArray::MainInst Buffer;
/*typedef ::VertexArray::MainInst<
	GL::BufferDataUsage::StaticDraw,
	GL::BufferDataUsage::StreamDraw,
	GL::DrawMode::Triangles
> Buffer;*/
};

#endif