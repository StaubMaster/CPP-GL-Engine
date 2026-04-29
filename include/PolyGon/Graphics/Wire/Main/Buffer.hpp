#ifndef  POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Point2D.hpp"
# include "Graphics/Attribute/ColorF4.hpp"

namespace PolyGonWire
{
namespace Main
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::Point2D	Pos;
	::Attribute::ColorF4	Col;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
};
};
};

#endif