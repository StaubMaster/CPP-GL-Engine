#include "PolyHedra/Simple3D/BufferArray.hpp"

# include "Graphics/Shader/Base.hpp"
# include "OpenGL/openGL.h"



PolyHedra_Simple3D::BufferArray::BufferArray() :
	::BufferArray::Base(),
	Main(0, 1, 2),
	Inst(3, 4),
	DrawMode(GL_TRIANGLES)
{
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
PolyHedra_Simple3D::BufferArray::~BufferArray()
{ }

PolyHedra_Simple3D::BufferArray::BufferArray(const BufferArray & other) :
	::BufferArray::Base(),
	Main(other.Main),
	Inst(other.Inst),
	DrawMode(other.DrawMode)
{
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
PolyHedra_Simple3D::BufferArray & PolyHedra_Simple3D::BufferArray::operator=(const BufferArray & other)
{
	Main = other.Main;
	Inst = other.Inst;
	DrawMode = other.DrawMode;
	return *this;
}



void PolyHedra_Simple3D::BufferArray::Draw()
{
	Bind();
	glDrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
