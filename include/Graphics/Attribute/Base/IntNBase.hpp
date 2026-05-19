#ifndef  ATTRIBUTE_INT_N_BASE_HPP
# define ATTRIBUTE_INT_N_BASE_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "OpenGLTypes.hpp"

namespace Attribute
{
class IntNBase : public Attribute::Base
{
	protected:
	void	LogInfoBase(GL::AttributeIntType type, unsigned int size0, unsigned int size1) const;

	protected:
	GL::AttributeLocation	Index;

	public:
	virtual ~IntNBase();
	IntNBase() = delete;
	IntNBase(Buffer::Array & buffer);

	IntNBase(const IntNBase & other) = delete;
	IntNBase(Buffer::Array & buffer, const IntNBase & other);
	IntNBase & operator=(const IntNBase & other);

	public:
	void	Change(GL::AttributeLocation index);
};
};

#endif