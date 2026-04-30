#ifndef  POLYGON_GRAPHICS_WIRE_ELEM_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_ELEM_BUFFER_HPP

# include "Graphics/Buffer/Element.hpp"

namespace PolyGonWire
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