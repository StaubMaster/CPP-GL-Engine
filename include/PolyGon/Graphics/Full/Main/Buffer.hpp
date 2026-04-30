#ifndef  POLYGON_GRAPHICS_FULL_MAIN_BUFFER_HPP
# define POLYGON_GRAPHICS_FULL_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/TypeDefs/VectorF2.hpp"
# include "Graphics/Attribute/TypeDefs/ColorF4.hpp"

namespace PolyGonFull
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
	Buffer(VertexArray & vertex_array, const Buffer & other);
};
};
};

#endif