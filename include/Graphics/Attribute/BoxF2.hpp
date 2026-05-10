#ifndef  ATTRIB_BOX_F_2_HPP
# define ATTRIB_BOX_F_2_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "Graphics/Attribute/TypeDefs/VectorF2.hpp"

namespace Attribute
{
class BoxF2 : public Attribute::Base
{
	public:
	Attribute::VectorF2		Min;
	Attribute::VectorF2		Max;

	public:
	~BoxF2();
	BoxF2() = delete;
	BoxF2(Buffer::Array & buffer);

	BoxF2(const BoxF2 & other) = delete;
	BoxF2(Buffer::Array & buffer, const BoxF2 & other);
	BoxF2 & operator=(const BoxF2 & other);

	public:
	void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override;
};
typedef BoxF2 BoxF2;
};

#endif