#ifndef  ATTRIB_TRANS_2D_HPP
# define ATTRIB_TRANS_2D_HPP

# include "Graphics/Attribute/Base/Base.hpp"

# include "Graphics/Attribute/Point2D.hpp"
# include "Graphics/Attribute/Angle2D.hpp"

namespace Attribute
{
class Trans2D : public Attribute::Base
{
	public:
	Attribute::Point2D Pos;
	Attribute::Angle2D Rot;

	public:
	void LogInfo() const override;

	public:
	~Trans2D();
	Trans2D();

	Trans2D(const Trans2D & other);
	Trans2D & operator=(const Trans2D & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif