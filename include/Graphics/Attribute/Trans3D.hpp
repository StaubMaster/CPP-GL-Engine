
#ifndef  ATTRIB_TRANS_3D_HPP
# define ATTRIB_TRANS_3D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Point3D.hpp"
# include "Angle3D.hpp"

namespace Attribute
{
class Trans3D : public Attribute::Base
{
	private:
	Attribute::Point3D Pos;
	Attribute::Angle3D Rot;

	public:
	Trans3D();
	Trans3D(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexPos,
		unsigned int indexRot
	);
	~Trans3D();

	Trans3D(const Trans3D & other);
	Trans3D & operator=(const Trans3D & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif
