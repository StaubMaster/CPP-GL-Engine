#ifndef  POLYHEDRA_MAIN_BUFFER_HPP
# define POLYHEDRA_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Point3D.hpp"

namespace BufferArray { class Base; };

namespace PolyHedra_Main
{
class Buffer : public ::Buffer::Attribute
{
	public:
	::Attribute::Point3D	Position;
	::Attribute::Point3D	Normal;
	::Attribute::Point3D	Texture;

	public:
	~Buffer();
	Buffer(BufferArray::Base & buffer_array);

	Buffer(const Buffer & other);
	Buffer & operator=(const Buffer & other);
};
};

#endif