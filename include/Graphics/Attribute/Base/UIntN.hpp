#ifndef  ATTRIBUTE_UINT_N_HPP
# define ATTRIBUTE_UINT_N_HPP

# include "Graphics/Attribute/Base/UIntNBase.hpp"

# include "OpenGLTypes.hpp"
# include "OpenGL.hpp"

namespace Attribute
{
template<unsigned int Size0, unsigned int Size1>
class UIntN : public Attribute::UIntNBase
{
	public:
	void	LogInfo() const override
	{
		LogInfoBase(GL::AttributeIntType::UnsignedInt, Size0, Size1);
	}

	public:
	virtual ~UIntN() { }
	UIntN() = delete;
	UIntN(Buffer::Array & buffer)
		: UIntNBase(buffer)
	{ }

	UIntN(const UIntN & other) = delete;
	UIntN(Buffer::Array & buffer, const UIntN & other)
		: Attribute::UIntNBase(buffer, other)
	{ }
	UIntN & operator=(const UIntN & other)
	{
		Attribute::Base::operator=(other);
		return *this;
	}

	public:
	void	Change(GL::AttributeLocation index)
	{
		Index = index;
	}

	public:
	void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const override
	{
		for (unsigned int s = 0; s < Size1; s++)
		{
			if (Index != -1)
			{
				GL::EnableVertexAttribArray(Index + s);
				GL::VertexAttribDivisor(Index + s, divisor);
				GL::VertexAttribIPointer(Index + s, Size0, GL::AttributeIntType::UnsignedInt, stride, offset);
			}
			offset += Size0 * sizeof(unsigned int);
		}
	}
};
};

#endif