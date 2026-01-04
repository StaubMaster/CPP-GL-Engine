#ifndef  SIMPLE3D_BUFFER_HPP
# define SIMPLE3D_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

namespace Simple3D
{
class Buffer : public ::Buffer::Attribute
{
	private:
	::Attribute::Trans3D	Trans;

	public:
	Buffer(
		unsigned int indexTransPos,
		unsigned int indexTransRot
	);
	~Buffer();

	Buffer(const Buffer & other);
	Buffer & operator=(const Buffer & other);
};
};

#endif