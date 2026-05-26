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
	::Buffer::Array		MainBuffer;
	GL::DrawMode		Mode;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~Main() { }
	Main()
		: VertexArray()
		, MainBuffer(*this, usage_main)
		, Mode(mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Trim();
	}

	Main(const Main & other)
		: VertexArray(other)
		, MainBuffer(*this, other.MainBuffer)
		, Mode(other.Mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Trim();
	}
	Main & operator=(const Main & other)
	{
		VertexArray::operator=(other);
		MainBuffer = other.MainBuffer;
		Mode = other.Mode;
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