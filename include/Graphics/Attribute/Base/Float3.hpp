#ifndef  ATTRIB_FLOAT_3_HPP
# define ATTRIB_FLOAT_3_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float3 : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location;

	public:
	void LogInfo() const override;

	public:
	virtual ~Float3();
	Float3();

	Float3(const Float3 & other);
	Float3 & operator=(const Float3 & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif