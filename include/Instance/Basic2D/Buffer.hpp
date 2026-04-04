#ifndef  INSTANCE_BASIC_2D_BUFFER_HPP
# define INSTANCE_BASIC_2D_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"
# include "Graphics/Attribute/Base/Float3x3.hpp"

namespace Instance
{
namespace Basic2D
{
class Buffer : public ::Buffer::Attribute
{
	public:
	::Attribute::Float3x3	Trans;
	public:
	~Buffer();
	Buffer(BufferArray::Base & buffer_array);
};
};
};

#endif