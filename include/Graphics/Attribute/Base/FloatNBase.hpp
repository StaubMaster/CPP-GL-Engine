#ifndef  ATTRIBUTE_FLOAT_N_BASE_HPP
# define ATTRIBUTE_FLOAT_N_BASE_HPP

# include "Graphics/Attribute/Base/Base.hpp"
# include "OpenGLTypes.hpp"

namespace Attribute
{
class FloatNBase : public Attribute::Base
{
	protected:
	void	LogInfoBase(GL::AttributeType type, unsigned int size0, unsigned int size1) const;

	protected:
	GL::AttributeLocation	Index;

	public:
	virtual ~FloatNBase();
	FloatNBase() = delete;
	FloatNBase(Buffer::Array & buffer);

	FloatNBase(const FloatNBase & other) = delete;
	FloatNBase(Buffer::Array & buffer, const FloatNBase & other);
	FloatNBase & operator=(const FloatNBase & other);

	public:
	void	Change(GL::AttributeLocation index);
};
};

#endif