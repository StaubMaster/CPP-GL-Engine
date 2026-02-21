#ifndef  ATTRIB_FLOAT_2X2_HPP
# define ATTRIB_FLOAT_2X2_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float2x2 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location0;
	Attribute::LocationFloatN Location1;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float2x2();
	Float2x2();

	Float2x2(const Float2x2 & other);
	Float2x2 & operator=(const Float2x2 & other);

	public:
	void Change(GL::AttributeLocation index0, GL::AttributeLocation index1);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif