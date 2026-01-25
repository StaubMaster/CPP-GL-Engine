#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Base.hpp"

# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Miscellaneous/Container/Fixed.hpp"
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
	GL::BufferTarget	Target;
	GL::BufferDataUsage	Usage;
	unsigned int DataSize;
	Container::Fixed<::Attribute::Base*> Attributes;
	unsigned int DrawCount;

	public:
	Attribute();
	Attribute(GL::BufferTarget target, GL::BufferDataUsage usage, unsigned int data_size);
	~Attribute();

	Attribute(const Attribute & other);
	Attribute & operator=(const Attribute & other);

	public:
	void Change(const Container::Void & data);
};
};

#endif