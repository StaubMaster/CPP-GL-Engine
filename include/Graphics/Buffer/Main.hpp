#ifndef  BUFFER_ARRAY_MAIN_HPP
# define BUFFER_ARRAY_MAIN_HPP

# include "Graphics/Buffer/VertexArray.hpp"
# include "Graphics/Buffer/Array.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"

# include "OpenGL.hpp"

namespace BufferArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::DrawMode mode
>
class Main : public VertexArray
{
	public:
	GL::DrawMode		Mode;
	::Buffer::Array		MainBuffer;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~Main() { }
	Main()
		: VertexArray()
		, Mode(mode)
		, MainBuffer(*this, usage_main)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Trim();
	}

	Main(const Main & other)
		: VertexArray(other)
		, Mode(other.Mode)
		, MainBuffer(*this, other.MainBuffer)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Trim();
	}
	Main & operator=(const Main & other)
	{
		VertexArray::operator=(other);
		Mode = other.Mode;
		MainBuffer = other.MainBuffer;
		return *this;
	}

	public:
	void Draw()
	{
		for (unsigned int i = 0; i < Textures.Count(); i++)
		{
			Textures[i] -> Bind();
		}
		Bind();
		GL::DrawArrays(Mode, 0, MainBuffer.Count);
	}
};
};

#endif