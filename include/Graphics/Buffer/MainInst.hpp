#ifndef  BUFFER_ARRAY_MAIN_INST_HPP
# define BUFFER_ARRAY_MAIN_INST_HPP

# include "Graphics/VertexArray/Base.hpp"
# include "Graphics/Buffer/Array.hpp"

# include "Generics/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"

# include "OpenGL.hpp"

namespace VertexArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::BufferDataUsage usage_inst,
	GL::DrawMode mode
>
class MainInst : public Base
{
	public:
	::Buffer::Array		MainBuffer;
	::Buffer::Array		InstBuffer;
	GL::DrawMode		Mode;

	public:
	virtual ~MainInst() { }
	MainInst()
		: Base()
		, MainBuffer(usage_main)
		, InstBuffer(usage_inst)
		, Mode(mode)
	{ }

	MainInst(const MainInst & other)
		: Base(other)
		, MainBuffer(other.MainBuffer)
		, InstBuffer(other.InstBuffer)
		, Mode(other.Mode)
	{ }
	MainInst & operator=(const MainInst & other)
	{
		Base::operator=(other);
		MainBuffer = other.MainBuffer;
		InstBuffer = other.InstBuffer;
		Mode = other.Mode;
		return *this;
	}

	public:
	void	Create() override
	{
		Base::Create();
		MainBuffer.Create();
		InstBuffer.Create();
	}
	void	Delete() override
	{
		Base::Delete();
		MainBuffer.Delete();
		InstBuffer.Delete();
	}

	public:
	void	Init() override
	{
		Bind();
		MainBuffer.Bind();
		InstBuffer.Bind();
	}
	void	Draw() override
	{
		Init();
		Bind();
		GL::DrawArraysInstanced(Mode, 0, MainBuffer.Count, InstBuffer.Count);
	}
};
};

#endif