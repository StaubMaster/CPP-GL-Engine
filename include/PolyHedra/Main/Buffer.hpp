#ifndef  POLYHEDRA_MAIN_BUFFER_HPP
# define POLYHEDRA_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Point3D.hpp"

namespace PolyHedra_Main
{
class Buffer : public ::Buffer::Attribute
{
	private:
	::Attribute::Point3D	Position;
	::Attribute::Point3D	Normal;
	::Attribute::Point3D	Texture;

	public:
	Buffer(
		unsigned int indexPosition,
		unsigned int indexNormal,
		unsigned int indexTexture
	);
	~Buffer();

	Buffer(const Buffer & other);
	Buffer & operator=(const Buffer & other);
};
};

#endif