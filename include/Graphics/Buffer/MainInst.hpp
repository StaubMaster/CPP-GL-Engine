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
	GL::DrawMode		Mode;
	::Buffer::Array		Main;
	::Buffer::Array		Inst;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainInst() { }
	MainInst()
		: VertexArray()
		, Mode(mode)
		, Main(*this, usage_main)
		, Inst(*this, usage_inst)
	{
		Buffers.Insert(&Main);
		Buffers.Insert(&Inst);
		Buffers.Trim();
	}

	MainInst(const MainInst & other)
		: VertexArray(other)
		, Mode(other.Mode)
		, Main(*this, other.Main)
		, Inst(*this, other.Inst)
	{
		Buffers.Insert(&Main);
		Buffers.Insert(&Inst);
		Buffers.Trim();
	}
	MainInst & operator=(const MainInst & other)
	{
		VertexArray::operator=(other);
		Mode = other.Mode;
		Main = other.Main;
		Inst = other.Inst;
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
		GL::DrawArraysInstanced(Mode, 0, Main.Count, Inst.Count);
	}
};
};

#endif