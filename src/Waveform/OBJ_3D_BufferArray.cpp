#include "Waveform/OBJ_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



OBJ_3D_BufferArray::OBJ_3D_BufferArray() :
	//Instance_Base_BufferArray(
	//	new OBJ_MainBuffer(0, 1, 2, 3, 4, 5, 6, 7),
	//	new Simple3D_InstBuffer(8, 9),
	//	GL_TRIANGLES)
	BufferArray::Base(),
	Main(0, 1, 2, 3, 4, 5, 6, 7),
	Inst(8, 9),
	DrawMode(GL_TRIANGLES)
{ }
OBJ_3D_BufferArray::~OBJ_3D_BufferArray()
{ }



void OBJ_3D_BufferArray::Draw()
{
	Bind();
	glDrawArraysInstanced(DrawMode, 0, Main.DrawCount, Inst.DrawCount);
}
