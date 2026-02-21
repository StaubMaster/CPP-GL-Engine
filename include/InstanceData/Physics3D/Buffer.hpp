#ifndef  PHYSICS3D_BUFFER_HPP
# define PHYSICS3D_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

namespace BufferArray { class Base; };

namespace Physics3D
{
class Buffer : public ::Buffer::Attribute
{
	public:
	::Attribute::Trans3D	Trans;
	::Attribute::Trans3D	Vel;

	public:
	~Buffer();
	Buffer(BufferArray::Base & buffer_array);
};
};

#endif