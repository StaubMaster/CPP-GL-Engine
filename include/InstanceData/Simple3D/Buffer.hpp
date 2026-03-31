#ifndef  SIMPLE3D_BUFFER_HPP
# define SIMPLE3D_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

namespace BufferArray { class Base; };

namespace Simple3D
{
class Buffer : public ::Buffer::Attribute
{
	public:
	::Attribute::Trans3D	Trans;

	public:
	~Buffer();
	Buffer(BufferArray::Base & buffer_array);

	Buffer(const Buffer & other);
	Buffer & operator=(const Buffer & other);
};
};

#endif