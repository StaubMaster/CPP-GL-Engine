#include "Waveform/OBJ_3D_BufferArray.hpp"

#include "OpenGL.hpp"



OBJ_3D_BufferArray::OBJ_3D_BufferArray() :
	BufferArray::Base(),
	Main(0, 1, 2, 3, 4, 5, 6, 7),
	Inst(8, 9),
	DrawMode(GL::DrawMode::Triangles)
{
	Buffers.Allocate(2);
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
OBJ_3D_BufferArray::~OBJ_3D_BufferArray()
{ }



void OBJ_3D_BufferArray::Draw()
{
	Bind();
	GL::DrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
