#ifndef  ATTRIBUTE_BASE_HPP
# define ATTRIBUTE_BASE_HPP

namespace Attribute
{
class Base
{
	public:
	Base();
	virtual ~Base();

	Base(const Base & other);
	Base & operator=(const Base & other);

	public:
	virtual void Bind(const unsigned char * & offset) const = 0;
};
};

#endif