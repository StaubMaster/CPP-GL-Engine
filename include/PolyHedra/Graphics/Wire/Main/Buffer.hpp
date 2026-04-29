#ifndef  POLYHEDRA_GRAPHICS_WIRE_MAIN_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_WIRE_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/VectorF3.hpp"
# include "Graphics/Attribute/ColorF4.hpp"

namespace PolyHedraWire
{
namespace Main
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::VectorF3	Pos;
	::Attribute::ColorF4	Col;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
};
};
};

#endif