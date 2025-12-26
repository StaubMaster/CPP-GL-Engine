#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Base.hpp"

# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Miscellaneous/Container/Base.hpp"

# include "Debug.hpp"
# include "OpenGL/openGL.h"
# include <sstream>



namespace Buffer
{
class Attribute : public Base
{
	private:
	public:
	unsigned int Target;
	unsigned int Usage;
	unsigned int DataSize;
	Container::Base<::Attribute::Base*> Attributes;
	unsigned int DrawCount;

	public:
	Attribute();
	Attribute(unsigned int target, unsigned int usage, unsigned int data_size);
	~Attribute();

	Attribute(const Attribute & other);
	Attribute & operator=(const Attribute & other);

	public:
	void Bind(const void * data, unsigned int count);
};
};

#endif