#ifndef  ATTRIB_FLOAT_4X4_HPP
# define ATTRIB_FLOAT_4X4_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float4x4 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location0;
	Attribute::LocationFloatN Location1;
	Attribute::LocationFloatN Location2;
	Attribute::LocationFloatN Location3;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float4x4();
	Float4x4();

	Float4x4(const Float4x4 & other);
	Float4x4 & operator=(const Float4x4 & other);

	public:
	void Change(GL::AttributeLocation index0, GL::AttributeLocation index1, GL::AttributeLocation index2, GL::AttributeLocation index3);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif