#ifndef  ATTRIB_ANGLE_2D_HPP
# define ATTRIB_ANGLE_2D_HPP

# include "Graphics/Attribute/Base/Float2x2.hpp"

namespace Attribute
{
class Angle2D : public Attribute::Float2x2
{
	public:
	~Angle2D();
	Angle2D();

	Angle2D(const Angle2D & other);
	Angle2D & operator=(const Angle2D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif