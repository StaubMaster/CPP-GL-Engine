#ifndef  ATTRIB_FLOAT_HPP
# define ATTRIB_FLOAT_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Buffer { class Attribute; };

namespace Attribute
{
class Float : public Attribute::FloatN
{
	public:
	virtual ~Float();
	Float() = delete;
	Float(Buffer::Array & buffer);

	Float(const Float & other);
	Float & operator=(const Float & other);
};
};

#endif