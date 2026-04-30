#ifndef  ATTRIB_FLOAT_HPP
# define ATTRIB_FLOAT_HPP

# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
typedef Attribute::FloatN<1, 1> Float;
/*class Float : public Attribute::FloatN<1, 1>
{
	public:
	virtual ~Float();
	Float() = delete;
	Float(Buffer::Array & buffer);

	Float(const Float & other) = delete;
	Float(Buffer::Array & buffer, const Float & other);
	Float & operator=(const Float & other);
};*/
};

#endif