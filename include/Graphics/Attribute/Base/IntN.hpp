#ifndef  ATTRIBUTE_INT_N_HPP
# define ATTRIBUTE_INT_N_HPP

# include "Graphics/Attribute/Base/IntNBase.hpp"

# include "OpenGLTypes.hpp"
# include "OpenGL.hpp"

namespace Attribute
{
template<unsigned int Size0, unsigned int Size1>
class IntN : public Attribute::IntNBase
{
	public:
	void	LogInfo() const override
	{
		LogInfoBase(GL::AttributeIntType::Int, Size0, Size1);
	}

	public:
	virtual ~IntN() { }
	IntN() = delete;
	IntN(Buffer::Array & buffer)
		: IntNBase(buffer)
	{ }

	IntN(const IntN & other) = delete;
	IntN(Buffer::Array & buffer, const IntN & other)
		: Attribute::IntNBase(buffer, other)
	{ }
	IntN & operator=(const IntN & other)
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
				GL::VertexAttribIPointer(Index + s, Size0, GL::AttributeIntType::Int, stride, offset);
			}
			offset += Size0 * sizeof(int);
		}
	}
};
};

#endif