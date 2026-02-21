#ifndef  ATTRIB_FLOAT_N_HPP
# define ATTRIB_FLOAT_N_HPP

# include "Graphics/Attribute/Base/Location.hpp"

# include "OpenGLTypes.hpp"

namespace Attribute
{
class LocationFloatN : public Attribute::Location
{
	public:
	~LocationFloatN();
	LocationFloatN(unsigned int count);

	LocationFloatN(const LocationFloatN & other);
	LocationFloatN & operator=(const LocationFloatN & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif