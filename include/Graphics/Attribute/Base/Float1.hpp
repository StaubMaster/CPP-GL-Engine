#ifndef  ATTRIB_FLOAT_1_HPP
# define ATTRIB_FLOAT_1_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float1 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float1();
	Float1();

	Float1(const Float1 & other);
	Float1 & operator=(const Float1 & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif