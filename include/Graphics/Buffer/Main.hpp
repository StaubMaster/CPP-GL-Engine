#ifndef  BUFFER_ARRAY_MAIN_HPP
# define BUFFER_ARRAY_MAIN_HPP

# include "Graphics/VertexArray/Base.hpp"
# include "Graphics/Buffer/Array.hpp"

# include "Generics/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"

# include "OpenGL.hpp"

namespace VertexArray
{
template<
	GL::BufferDataUsage usage_main,
	GL::DrawMode mode
>
class Main : public Base
{
	public:
	::Buffer::Array		MainBuffer;
	GL::DrawMode		Mode;

	public:
	virtual ~Main() { }
	Main()
		: Base()
		, MainBuffer(usage_main)
		, Mode(mode)
	{ }

	Main(const Main & other)
		: Base(other)
		, MainBuffer(other.MainBuffer)
		, Mode(other.Mode)
	{ }
	Main & operator=(const Main & other)
	{
		Base::operator=(other);
		MainBuffer = other.MainBuffer;
		Mode = other.Mode;
		return *this;
	}

	public:
	void	Create() override
	{
		Base::Create();
		MainBuffer.Create();
	}
	void	Delete() override
	{
		Base::Delete();
		MainBuffer.Delete();
	}

	public:
	void	Init() override
	{
		Bind();
		MainBuffer.Bind();
	}
	void Draw() override
	{
		Init();
		Bind();
		GL::DrawArrays(Mode, 0, MainBuffer.Count);
	}
};
};

#endif