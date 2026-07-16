#include "Graphics/VertexArray/MainInst.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"



VertexArray::MainInst::~MainInst()
{ }
VertexArray::MainInst::MainInst()
	: Base()
	, Mode(GL::DrawMode::Triangles)
	, MainBuffer(GL::BufferDataUsage::StaticDraw)
	, InstBuffer(GL::BufferDataUsage::DynamicDraw)
	, MainLayout(nullptr)
	, InstLayout(nullptr)
{ }



void VertexArray::MainInst::Create()
{
	Base::Create();
	MainBuffer.Create();
	InstBuffer.Create();
}
void VertexArray::MainInst::Delete()
{
	Base::Delete();
	MainBuffer.Delete();
	InstBuffer.Delete();
}

void VertexArray::MainInst::Init()
{
	Bind();

	MainBuffer.Bind();
	if (MainLayout != nullptr)
	{
		MainLayout -> Bind();
	}

	InstBuffer.Bind();
	if (InstLayout != nullptr)
	{
		InstLayout -> Bind();
	}
}

void VertexArray::MainInst::Draw()
{
	GL::DrawArraysInstanced(Mode, 0, MainBuffer.Count, InstBuffer.Count);
}
