#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Base.hpp"

# include "Graphics/Attribute/Base/Base.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Void.hpp"

# include "Debug.hpp"
# include "OpenGLEnums.hpp"
# include <sstream>



namespace Buffer
{
class Attribute : public Base
{
	private:
	public:
	GL::BufferTarget		Target;
	GL::BufferDataUsage		Usage;
	GL::AttributeDivisor	Divisor;
	unsigned int			Stride;
	unsigned int			DrawCount;
	Container::Binary<::Attribute::Base*>	Attributes;

	public:
	Attribute();
	Attribute(GL::BufferTarget target, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, unsigned int stride);
	~Attribute();

	Attribute(const Attribute & other);
	Attribute & operator=(const Attribute & other);

	public:
	void Change(const Container::Void & data);
};
};

#endif