#include "Graphics/Buffer/MainInst.hpp"
#include "Graphics/Texture/Base.hpp"
#include "OpenGL.hpp"



BufferArray::MainInst::~MainInst() { }
BufferArray::MainInst::MainInst(GL::DrawMode mode)
	: BufferArray::Base()
	, Mode(mode)
	, MainPtr(nullptr)
	, InstPtr(nullptr)
	, Textures()
{ }



void BufferArray::MainInst::Draw()
{
	if (MainPtr == nullptr || InstPtr == nullptr) { return; }
	for (unsigned int i = 0; i < Textures.Count(); i++)
	{
		Textures[i] -> Bind();
	}
	Bind();
	GL::DrawArraysInstanced(Mode, 0, MainPtr -> DrawCount, InstPtr -> DrawCount);
}
