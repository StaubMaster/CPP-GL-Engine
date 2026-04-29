#ifndef  ATTRIBUTE_FLOAT_N_HPP
# define ATTRIBUTE_FLOAT_N_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class FloatN : public Attribute::Base
{
	private:
	Attribute::LocationFloatN Location;

	public:
	virtual ~FloatN();
	FloatN() = delete;
	FloatN(Buffer::Array & buffer, unsigned int size0, unsigned int size1);

	FloatN(const FloatN & other);
	FloatN & operator=(const FloatN & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif