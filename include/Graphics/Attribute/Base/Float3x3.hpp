#ifndef  ATTRIB_FLOAT_3X3_HPP
# define ATTRIB_FLOAT_3X3_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float3x3 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location0;
	Attribute::LocationFloatN Location1;
	Attribute::LocationFloatN Location2;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float3x3();
	Float3x3();

	Float3x3(const Float3x3 & other);
	Float3x3 & operator=(const Float3x3 & other);

	public:
	void Change(GL::AttributeLocation index0, GL::AttributeLocation index1, GL::AttributeLocation index2);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif