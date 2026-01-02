#include "PolyHedra/Simple3D/PolyHedra_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
//# include <iostream>



PolyHedra_3D_BufferArray::PolyHedra_3D_BufferArray() :
	//Instance_Base_BufferArray(
	//	new PolyHedra_MainBuffer(0, 1, 2),
	//	new Simple3D_InstBuffer(3, 4),
	//	GL_TRIANGLES)
	Buffer::ArrayBase(),
	Main(0, 1, 2),
	Inst(3, 4),
	DrawMode(GL_TRIANGLES)
{ }
PolyHedra_3D_BufferArray::~PolyHedra_3D_BufferArray()
{ }

PolyHedra_3D_BufferArray::PolyHedra_3D_BufferArray(const PolyHedra_3D_BufferArray & other) :
	Buffer::ArrayBase(),
	Main(other.Main),
	Inst(other.Inst),
	DrawMode(other.DrawMode)
{ }
PolyHedra_3D_BufferArray & PolyHedra_3D_BufferArray::operator=(const PolyHedra_3D_BufferArray & other)
{
	Main = other.Main;
	Inst = other.Inst;
	DrawMode = other.DrawMode;
	return *this;
}



void PolyHedra_3D_BufferArray::CreateBuffers()
{
	Main.Create();
	Inst.Create();
}
void PolyHedra_3D_BufferArray::DeleteBuffers()
{
	Main.Delete();
	Inst.Delete();
}



void PolyHedra_3D_BufferArray::Draw()
{
	Bind();
	glDrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
