#include "PolyHedra/Simple3D/BufferArray.hpp"

# include "Graphics/Shader/Base.hpp"
# include "OpenGL.hpp"



PolyHedra_Simple3D::BufferArray::BufferArray() :
	::BufferArray::Base(),
	Main(0, 1, 2),
	Inst(3, 4),
	Texture(),
	DrawMode(GL::DrawMode::Triangles)
{
	Buffers.Allocate(2);
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
PolyHedra_Simple3D::BufferArray::~BufferArray()
{ }

PolyHedra_Simple3D::BufferArray::BufferArray(const BufferArray & other) :
	::BufferArray::Base(),
	Main(other.Main),
	Inst(other.Inst),
	Texture(other.Texture),
	DrawMode(other.DrawMode)
{
	Buffers.Allocate(2);
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
PolyHedra_Simple3D::BufferArray & PolyHedra_Simple3D::BufferArray::operator=(const BufferArray & other)
{
	Main = other.Main;
	Inst = other.Inst;
	Texture = other.Texture;
	DrawMode = other.DrawMode;
	return *this;
}



void PolyHedra_Simple3D::BufferArray::Draw()
{
	Texture.Bind();
	Bind();
	GL::DrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
