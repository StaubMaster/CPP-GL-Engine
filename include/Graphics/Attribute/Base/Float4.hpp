#ifndef  ATTRIB_FLOAT_4_HPP
# define ATTRIB_FLOAT_4_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float4 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float4();
	Float4();

	Float4(const Float4 & other);
	Float4 & operator=(const Float4 & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif