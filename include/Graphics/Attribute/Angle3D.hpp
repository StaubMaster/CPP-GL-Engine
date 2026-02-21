#ifndef  ATTRIB_ANGLE_3D_HPP
# define ATTRIB_ANGLE_3D_HPP

# include "Graphics/Attribute/Base/Float3x3.hpp"

namespace Attribute
{
class Angle3D : public Attribute::Float3x3
{
	public:
	~Angle3D();
	Angle3D();

	Angle3D(const Angle3D & other);
	Angle3D & operator=(const Angle3D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif