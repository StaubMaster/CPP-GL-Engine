#ifndef  ATTRIBUTE_BASE_HPP
# define ATTRIBUTE_BASE_HPP

# include "OpenGLTypes.hpp"

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
	virtual void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const = 0;
};
};

#endif