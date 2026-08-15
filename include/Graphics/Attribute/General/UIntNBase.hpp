#ifndef  ATTRIBUTE_UINT_N_BASE_HPP
# define ATTRIBUTE_UINT_N_BASE_HPP

# include "Graphics/Attribute/General/Base.hpp"
# include "OpenGLTypes.hpp"

namespace Attribute
{
class UIntNBase : public Attribute::Base
{
	protected:
	GL::AttributeLocation	Index = -1;

	public:
	virtual ~UIntNBase();

	public:
	UIntNBase() = delete;
	UIntNBase(const UIntNBase & other) = delete;
	UIntNBase & operator=(const UIntNBase & other);

	public:
	UIntNBase(Layout & layout);
	UIntNBase(Layout & layout, const UIntNBase & other);

	public:
	void	Change(GL::AttributeLocation index);

	protected:
	void	LogInfoBase(GL::AttributeIntType type, unsigned int size0, unsigned int size1) const;
};
};

#endif