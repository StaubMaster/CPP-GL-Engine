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
template<typename MainBufferType, typename ElemBufferType, typename InstBufferType>
class MainElemInst : public VertexArray
{
	public:
	GL::DrawMode	Mode;
	MainBufferType	Main;
	ElemBufferType	Elem;
	InstBufferType	Inst;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainElemInst() { }
	MainElemInst() = delete;
	MainElemInst(GL::DrawMode mode)
		: VertexArray()
		, Mode(mode)
		, Main(*this)
		, Elem(*this)
		, Inst(*this)
	{
		Buffers.Allocate(3);
		Buffers.Insert(&Main);
		Buffers.Insert(&Elem);
		Buffers.Insert(&Inst);
	}

	MainElemInst(const MainElemInst & other)
		: VertexArray(other)
		, Mode(other.Mode)
		, Main(*this, other.Main)
		, Elem(*this, other.Elem)
		, Inst(*this, other.Inst)
	{
		Buffers.Allocate(3);
		Buffers.Insert(&Main);
		Buffers.Insert(&Elem);
		Buffers.Insert(&Inst);
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