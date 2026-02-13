#ifndef  ATTRIB_ANGLE_2D_HPP
# define ATTRIB_ANGLE_2D_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Angle2D : public Attribute::Base
{
	private:
	Attribute::FloatN Location0;
	Attribute::FloatN Location1;

	public:
	Angle2D();
	Angle2D(
		unsigned int divisor,
		unsigned int stride,
		unsigned int index
	);
	~Angle2D();

	Angle2D(const Angle2D & other);
	Angle2D & operator=(const Angle2D & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif