#ifndef  ATTRIBUTE_BASE_HPP
# define ATTRIBUTE_BASE_HPP

# include "OpenGLTypes.hpp"

namespace Attribute
{
class Layout;
class Base
{
	public:
	virtual void	LogInfo() const;

	public:
	virtual ~Base();
	Base() = delete;
	Base(Layout & layout);

	Base(const Base & other) = delete;
	Base(Layout & layout, const Base & other);
	Base & operator=(const Base & other);

	public:
	virtual void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const = 0;
};
};

#endif