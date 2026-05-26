#ifndef  ATTRIBUTE_LAYOUT_HPP
# define ATTRIBUTE_LAYOUT_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "OpenGLEnums.hpp"

namespace Attribute
{
class Base;
class Layout
{
	public:
	void	LogInfo() const;

	public:
	Container::Binary<::Attribute::Base*>	Attributes;
	GL::AttributeDivisor					Divisor;
	GL::AttributeStride						Stride;

	public:
	virtual ~Layout();
	Layout() = delete;
	Layout(GL::AttributeDivisor divisor, GL::AttributeStride stride);

	Layout(const Layout & other);
	Layout & operator=(const Layout & other) = delete;

	public:
	void	Bind();
};
};

#endif