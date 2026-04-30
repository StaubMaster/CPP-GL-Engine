#ifndef  INSTANCE_BASIC_2D_BUFFER_HPP
# define INSTANCE_BASIC_2D_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/TypeDefs/Matrix3x3.hpp"

namespace Instance
{
namespace Basic2D
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::Matrix3x3	Trans;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
	Buffer(VertexArray & vertex_array, const Buffer & other);
};
};
};

#endif