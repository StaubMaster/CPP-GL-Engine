#include "Wavefront/Simple3D/BufferArray.hpp"
#include "OpenGL.hpp"



Wavefront::Simple3D::BufferArray::BufferArray() :
	::BufferArray::Base(),
	Main(0, 1, 2, 3, 4, 5, 6, 7),
	Inst(8, 9),
	DrawMode(GL::DrawMode::Triangles)
{
	Buffers.Allocate(2);
	Buffers.Insert(&Main);
	Buffers.Insert(&Inst);
}
Wavefront::Simple3D::BufferArray::~BufferArray()
{ }



void Wavefront::Simple3D::BufferArray::Draw()
{
	Bind();
	GL::DrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
