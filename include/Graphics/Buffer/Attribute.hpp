#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Base.hpp"

# include "Graphics/Attribute/Base/Base.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Void.hpp"

# include "OpenGLEnums.hpp"

namespace Buffer
{
class Attribute : public Base
{
	public:
	GL::BufferDataUsage		Usage;
	GL::AttributeDivisor	Divisor;
	unsigned int			Stride;
	unsigned int			DrawCount;
	Container::Binary<::Attribute::Base*>	Attributes;

	public:
	void LogInfo(bool self = true) const override;

	public:
	virtual ~Attribute();
	Attribute(::BufferArray::Base & buffer_array, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, GL::AttributeStride stride);

	Attribute(const Attribute & other);
	Attribute & operator=(const Attribute & other);

	public:
	void Change(const Container::Void & data);
};
};

#endif