#ifndef  ATTRIB_FLOAT_N_HPP
# define ATTRIB_FLOAT_N_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class FloatN : public Attribute::Base
{
	private:
	Attribute::Location Location;

	public:
	FloatN();
	FloatN(
		Buffer::Attribute & buffer,
		GL::AttributeID index
	);
	FloatN(
		Buffer::Attribute & buffer,
		GL::AttributeID index,
		unsigned int count
	);
	~FloatN();

	FloatN(const FloatN & other);
	FloatN & operator=(const FloatN & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif