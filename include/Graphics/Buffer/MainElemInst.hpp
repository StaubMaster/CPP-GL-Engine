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
	::Buffer::Array		MainBuffer;
	::Buffer::Element	ElemBuffer;
	::Buffer::Array		InstBuffer;
	GL::DrawMode		Mode;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainElemInst() { }
	MainElemInst()
		: VertexArray()
		, MainBuffer(*this, usage_main)
		, ElemBuffer(*this, usage_elem, index_type)
		, InstBuffer(*this, usage_inst)
		, Mode(mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Insert(&ElemBuffer);
		Buffers.Insert(&InstBuffer);
		Buffers.Trim();
	}

	MainElemInst(const MainElemInst & other)
		: VertexArray(other)
		, MainBuffer(*this, other.MainBuffer)
		, ElemBuffer(*this, other.ElemBuffer)
		, InstBuffer(*this, other.InstBuffer)
		, Mode(other.Mode)
	{
		Buffers.Insert(&MainBuffer);
		Buffers.Insert(&ElemBuffer);
		Buffers.Insert(&InstBuffer);
		Buffers.Trim();
	}
	MainElemInst & operator=(const MainElemInst & other)
	{
		VertexArray::operator=(other);
		MainBuffer = other.MainBuffer;
		ElemBuffer = other.ElemBuffer;
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
		GL::DrawElementsInstanced(Mode, ElemBuffer.Count, ElemBuffer.IndexType, InstBuffer.Count);
	}
};
};

#endif