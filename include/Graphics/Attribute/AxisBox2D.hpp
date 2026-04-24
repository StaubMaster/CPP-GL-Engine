#ifndef  ATTRIB_AXISBOX_2D_HPP
# define ATTRIB_AXISBOX_2D_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

namespace Attribute
{
class AxisBox2D : public Attribute::Base
{
	public:
	Attribute::LocationFloatN Min;
	Attribute::LocationFloatN Max;

	public:
	void LogInfo() const override;

	public:
	~AxisBox2D();
	AxisBox2D();

	AxisBox2D(const AxisBox2D & other);
	AxisBox2D & operator=(const AxisBox2D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif