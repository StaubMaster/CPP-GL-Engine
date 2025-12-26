#ifndef  PHYSICS_3D_INST_BUFFER_HPP
# define PHYSICS_3D_INST_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

class Physics3D_InstBuffer : public Buffer::Attribute
{
	private:
	::Attribute::Trans3D	Trans;
	::Attribute::Trans3D	Vel;

	public:
	Physics3D_InstBuffer(
		unsigned int indexTransPos,
		unsigned int indexTransRot,
		unsigned int indexVelPos,
		unsigned int indexVelRot
	);
	~Physics3D_InstBuffer();
};

#endif