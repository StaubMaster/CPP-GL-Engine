#ifndef  INSTANCE_BASIC_2D_BUFFER_HPP
# define INSTANCE_BASIC_2D_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Base/Float3x3.hpp"

namespace Instance
{
namespace Basic2D
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::Float3x3	Trans;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
};
};
};

#endif