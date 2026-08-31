#ifndef  ATTRIBUTE_BASE_HPP
# define ATTRIBUTE_BASE_HPP

# include "OpenGLTypes.hpp"

namespace Attribute
{
class Layout;
class Base
{
	public:
	virtual ~Base();

	public:
	Base() = delete;
	Base(const Base & other) = delete;
	Base & operator=(const Base & other);

	public:
	Base(Layout & layout);
	Base(Layout & layout, const Base & other);

	public:
	virtual void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const = 0;

	public:
	virtual unsigned int	CalcSize() const = 0;

	public:
	virtual void	LogInfo() const;
};
};

#endif