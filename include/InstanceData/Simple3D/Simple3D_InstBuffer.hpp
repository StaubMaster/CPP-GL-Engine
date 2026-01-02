#ifndef  SIMPLE_3D_INST_BUFFER_HPP
# define SIMPLE_3D_INST_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

class Simple3D_InstBuffer : public Buffer::Attribute
{
	private:
	::Attribute::Trans3D	Trans;

	public:
	Simple3D_InstBuffer(
		unsigned int indexTransPos,
		unsigned int indexTransRot
	);
	~Simple3D_InstBuffer();

	Simple3D_InstBuffer(const Simple3D_InstBuffer & other);
	Simple3D_InstBuffer & operator=(const Simple3D_InstBuffer & other);
};

#endif