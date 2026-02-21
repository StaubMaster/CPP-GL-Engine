#ifndef  ATTRIB_UINT_1_HPP
# define ATTRIB_UINT_1_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class UInt1 : public Attribute::Base
{
	private:
	Attribute::Location Location;

	public:
	UInt1();
	UInt1(
		Buffer::Attribute & buffer,
		GL::AttributeLocation index
	);
	UInt1(
		Buffer::Attribute & buffer,
		GL::AttributeLocation index,
		unsigned int count
	);
	~UInt1();

	UInt1(const UInt1 & other);
	UInt1 & operator=(const UInt1 & other);

	public:
	void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
};

#endif