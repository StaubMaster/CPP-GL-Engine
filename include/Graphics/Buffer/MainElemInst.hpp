#ifndef  BUFFER_ARRAY_MAIN_ELEM_INST_HPP
# define BUFFER_ARRAY_MAIN_ELEM_INST_HPP

# include "Graphics/Buffer/VertexArray.hpp"
# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Buffer/Element.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"
# include "OpenGL.hpp"

namespace BufferArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::BufferDataUsage usage_elem, GL::DrawIndexType index_type,
	GL::BufferDataUsage usage_inst,
	GL::DrawMode mode
>
class MainElemInst : public VertexArray
{
	public:
	GL::DrawMode		Mode;
	::Buffer::Array		Main;
	::Buffer::Element	Elem;
	::Buffer::Array		Inst;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainElemInst() { }
	MainElemInst()
		: VertexArray()
		, Mode(mode)
		, Main(*this, usage_main)
		, Elem(*this, usage_elem, index_type)
		, Inst(*this, usage_inst)
	{
		Buffers.Insert(&Main);
		Buffers.Insert(&Elem);
		Buffers.Insert(&Inst);
		Buffers.Trim();
	}

	MainElemInst(const MainElemInst & other)
		: VertexArray(other)
		, Mode(other.Mode)
		, Main(*this, other.Main)
		, Elem(*this, other.Elem)
		, Inst(*this, other.Inst)
	{
		Buffers.Insert(&Main);
		Buffers.Insert(&Elem);
		Buffers.Insert(&Inst);
		Buffers.Trim();
	}
	MainElemInst & operator=(const MainElemInst & other)
	{
		VertexArray::operator=(other);
		Mode = other.Mode;
		Main = other.Main;
		Elem = other.Elem;
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
		GL::DrawElementsInstanced(Mode, Elem.Count, Elem.IndexType, Inst.Count);
	}
};
};

#endif