#ifndef  POLYHEDRA_GRAPHICS_WIRE_ELEM_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_WIRE_ELEM_BUFFER_HPP

# include "Graphics/Buffer/Element.hpp"

namespace PolyHedraWire
{
namespace Elem
{
class Buffer : public ::Buffer::Element
{
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
	Buffer(VertexArray & vertex_array, const Buffer & other);
};
};
};

#endif