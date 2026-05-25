#ifndef  INSTANCE_BASIC_3D_BUFFER_HPP
# define INSTANCE_BASIC_3D_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Layout.hpp"
# include "Graphics/Attribute/TypeDefs/Matrix4x4.hpp"

namespace Instance
{
namespace Basic3D
{
/*class Buffer : public ::Buffer::Array
{
	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);
	Buffer(VertexArray & vertex_array, const Buffer & other);
};*/
class Layout : public ::Attribute::Layout
{
	public:
	::Attribute::Matrix4x4	Trans;
	::Attribute::Matrix4x4	Normal;
	public:
	~Layout();
	Layout();
	Layout(const Layout & other);
};
};
};

#endif