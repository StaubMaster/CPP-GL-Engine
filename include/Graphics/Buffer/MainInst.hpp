#ifndef  BUFFER_ARRAY_MAIN_INST_HPP
# define BUFFER_ARRAY_MAIN_INST_HPP

# include "Graphics/Buffer/ArrayBase.hpp"
# include "Graphics/Buffer/Attribute.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "Graphics/Texture/Base.hpp"

# include "OpenGL.hpp"

namespace BufferArray
{
template<typename MainBufferType, typename InstBufferType>
class MainInst : public BufferArray::Base
{
	public:
	GL::DrawMode	Mode;
	MainBufferType	Main;
	InstBufferType	Inst;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainInst() { }
	MainInst(GL::DrawMode mode)
		: BufferArray::Base()
		, Mode(mode)
		, Main(*this)
		, Inst(*this)
	{
		Buffers.Allocate(2);
		Buffers.Insert(&Main);
		Buffers.Insert(&Inst);
	}

	public:
	void Draw()
	{
		for (unsigned int i = 0; i < Textures.Count(); i++)
		{
			Textures[i] -> Bind();
		}
		Bind();
		GL::DrawArraysInstanced(Mode, 0, Main.DrawCount, Inst.DrawCount);
	}
};
};

#endif