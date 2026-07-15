#ifndef  BUFFER_ARRAY_MAIN_ELEM_INST_HPP
# define BUFFER_ARRAY_MAIN_ELEM_INST_HPP

# include "Graphics/VertexArray/Base.hpp"
# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Buffer/Element.hpp"

# include "Generics/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"
# include "OpenGL.hpp"

namespace VertexArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::BufferDataUsage usage_elem, GL::DrawIndexType index_type,
	GL::BufferDataUsage usage_inst,
	GL::DrawMode mode
>
class MainElemInst : public Base
{
	public:
	::Buffer::Array		MainBuffer;
	::Buffer::Element	ElemBuffer;
	::Buffer::Array		InstBuffer;
	GL::DrawMode		Mode;

	public:
	virtual ~MainElemInst() { }
	MainElemInst()
		: Base()
		, MainBuffer(usage_main)
		, ElemBuffer(usage_elem, index_type)
		, InstBuffer(usage_inst)
		, Mode(mode)
	{ }

	MainElemInst(const MainElemInst & other)
		: Base(other)
		, MainBuffer(other.MainBuffer)
		, ElemBuffer(other.ElemBuffer)
		, InstBuffer(other.InstBuffer)
		, Mode(other.Mode)
	{ }
	MainElemInst & operator=(const MainElemInst & other)
	{
		Base::operator=(other);
		MainBuffer = other.MainBuffer;
		ElemBuffer = other.ElemBuffer;
		InstBuffer = other.InstBuffer;
		Mode = other.Mode;
		return *this;
	}

	public:
	void	Create() override
	{
		Base::Create();
		MainBuffer.Create();
		ElemBuffer.Create();
		InstBuffer.Create();
	}
	void	Delete() override
	{
		Base::Delete();
		MainBuffer.Delete();
		ElemBuffer.Delete();
		InstBuffer.Delete();
	}

	public:
	void	Init() override
	{
		Bind();
		MainBuffer.Bind();
		ElemBuffer.Bind();
		InstBuffer.Bind();
	}
	void Draw() override
	{
		Init();
		Bind();
		GL::DrawElementsInstanced(Mode, ElemBuffer.Count, ElemBuffer.IndexType, InstBuffer.Count);
	}
};
};

#endif