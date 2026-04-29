#ifndef  INSTANCE_BASIC_3D_BUFFER_HPP
# define INSTANCE_BASIC_3D_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Matrix4x4.hpp"

namespace Instance
{
namespace Basic3D
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::Matrix4x4	Trans;
	::Attribute::Matrix4x4	Normal;
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
};
};
};

#endif