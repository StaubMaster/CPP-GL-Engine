#ifndef  ATTRIB_FLOAT_2_HPP
# define ATTRIB_FLOAT_2_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float2 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float2();
	Float2();

	Float2(const Float2 & other);
	Float2 & operator=(const Float2 & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif