#ifndef  ATTRIBUTE_FLOAT_N_HPP
# define ATTRIBUTE_FLOAT_N_HPP

# include "Graphics/Attribute/Base/FloatNBase.hpp"

# include "OpenGLTypes.hpp"
# include "OpenGL.hpp"

namespace Attribute
{
template<unsigned int Size0, unsigned int Size1>
class FloatN : public Attribute::FloatNBase
{
	public:
	void	LogInfo() const override
	{
		LogInfoBase(GL::AttributeType::Float, Size0, Size1);
	}

	public:
	virtual ~FloatN() { }
	FloatN() = delete;
	FloatN(Buffer::Array & buffer)
		: FloatNBase(buffer)
	{ }

	FloatN(const FloatN & other) = delete;
	FloatN(Buffer::Array & buffer, const FloatN & other)
		: Attribute::FloatNBase(buffer, other)
	{ }
	FloatN & operator=(const FloatN & other)
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
				GL::VertexAttribPointer(Index + s, Size0, GL::AttributeType::Float, GL_FALSE, stride, offset);
			}
			offset += Size0 * sizeof(float);
		}
	}
};
};

#endif