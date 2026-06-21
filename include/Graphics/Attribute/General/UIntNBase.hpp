#ifndef  ATTRIBUTE_UINT_N_BASE_HPP
# define ATTRIBUTE_UINT_N_BASE_HPP

# include "Graphics/Attribute/General/Base.hpp"
# include "OpenGLTypes.hpp"

namespace Attribute
{
class UIntNBase : public Attribute::Base
{
	protected:
	void	LogInfoBase(GL::AttributeIntType type, unsigned int size0, unsigned int size1) const;

	protected:
	GL::AttributeLocation	Index;

	public:
	virtual ~UIntNBase();
	UIntNBase() = delete;
	UIntNBase(Layout & layout);

	UIntNBase(const UIntNBase & other) = delete;
	UIntNBase(Layout & layout, const UIntNBase & other);
	UIntNBase & operator=(const UIntNBase & other);

	public:
	void	Change(GL::AttributeLocation index);
};
};

#endif