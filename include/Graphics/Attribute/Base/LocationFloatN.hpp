#ifndef  ATTRIBUTE_LOCATION_FLOAT_N_HPP
# define ATTRIBUTE_LOCATION_FLOAT_N_HPP

# include "Graphics/Attribute/Base/Location.hpp"

# include "OpenGLTypes.hpp"

namespace Attribute
{
class LocationFloatN : public Attribute::Location
{
	public:
	~LocationFloatN();
	LocationFloatN() = delete;
	LocationFloatN(
		Buffer::Array & buffer,
		unsigned int size0,
		unsigned int size1
	);

	LocationFloatN(const LocationFloatN & other);
	LocationFloatN & operator=(const LocationFloatN & other);

	public:
	void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif