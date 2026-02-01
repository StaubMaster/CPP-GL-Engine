#ifndef  ATTRIB_UINT_1_HPP
# define ATTRIB_UINT_1_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"

namespace Attribute
{
class UInt1 : public Attribute::Base
{
	private:
	Attribute::Location Location;

	public:
	UInt1();
	UInt1(
		unsigned int divisor,
		unsigned int stride,
		unsigned int index
	);
	~UInt1();

	UInt1(const UInt1 & other);
	UInt1 & operator=(const UInt1 & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif