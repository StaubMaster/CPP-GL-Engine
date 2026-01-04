#ifndef  PHYSICS3D_BUFFER_HPP
# define PHYSICS3D_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

namespace Physics3D
{
class Buffer : public ::Buffer::Attribute
{
	private:
	::Attribute::Trans3D	Trans;
	::Attribute::Trans3D	Vel;

	public:
	Buffer(
		unsigned int indexTransPos,
		unsigned int indexTransRot,
		unsigned int indexVelPos,
		unsigned int indexVelRot
	);
	~Buffer();
};
};

#endif