#ifndef  POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/VectorF2.hpp"
# include "Graphics/Attribute/ColorF4.hpp"

namespace PolyGonWire
{
namespace Main
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::VectorF2	Pos;
	::Attribute::ColorF4	Col;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
};
};
};

#endif