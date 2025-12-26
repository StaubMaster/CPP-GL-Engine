#ifndef  POLYHEDRA_MAIN_BUFFER_HPP
# define POLYHEDRA_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/Point2D.hpp"

class PolyHedra_MainBuffer : public Buffer::Attribute
{
	private:
	::Attribute::Point3D	Position;
	::Attribute::Point3D	Normal;
	::Attribute::Point2D	Texture;

	public:
	PolyHedra_MainBuffer(
		unsigned int indexPosition,
		unsigned int indexNormal,
		unsigned int indexTexture
	);
	~PolyHedra_MainBuffer();
};

#endif