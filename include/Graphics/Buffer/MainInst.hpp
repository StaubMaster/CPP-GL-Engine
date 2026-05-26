#ifndef  BUFFER_ARRAY_MAIN_INST_HPP
# define BUFFER_ARRAY_MAIN_INST_HPP

# include "Graphics/Buffer/VertexArray.hpp"
# include "Graphics/Buffer/Array.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"

# include "OpenGL.hpp"

namespace BufferArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::BufferDataUsage usage_inst,
	GL::DrawMode mode
>
class MainInst : public VertexArray
{
	public:
	::Buffer::Array		MainBuffer;
	::Buffer::Array		InstBuffer;
	GL::DrawMode		Mode;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainInst() { }
	MainInst()
		: VertexArray()
		, MainBuffer(*this, usage_main)
		, InstBuffer(*this, usage_inst)
		, Mode(mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Insert(&InstBuffer);
		Buffers.Trim();
	}

	MainInst(const MainInst & other)
		: VertexArray(other)
		, MainBuffer(*this, other.MainBuffer)
		, InstBuffer(*this, other.InstBuffer)
		, Mode(other.Mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Insert(&InstBuffer);
		Buffers.Trim();
	}
	MainInst & operator=(const MainInst & other)
	{
		VertexArray::operator=(other);
		MainBuffer = other.MainBuffer;
		InstBuffer = other.InstBuffer;
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
		GL::DrawArraysInstanced(Mode, 0, MainBuffer.Count, InstBuffer.Count);
	}
};
};

#endif