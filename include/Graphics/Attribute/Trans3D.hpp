#ifndef  ATTRIB_TRANS_3D_HPP
# define ATTRIB_TRANS_3D_HPP

# include "Graphics/Attribute/Base/Base.hpp"

# include "Point3D.hpp"
# include "Angle3D.hpp"

namespace Attribute
{
class Trans3D : public Attribute::Base
{
	public:
	Attribute::Point3D Pos;
	Attribute::Angle3D Rot;

	public:
	void LogInfo() const override;

	public:
	~Trans3D();
	Trans3D();

	Trans3D(const Trans3D & other);
	Trans3D & operator=(const Trans3D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif