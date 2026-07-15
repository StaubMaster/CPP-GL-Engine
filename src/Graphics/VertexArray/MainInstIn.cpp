#include "Graphics/VertexArray/MainInstIn.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"



VertexArray::MainInstIn::~MainInstIn()
{ }
VertexArray::MainInstIn::MainInstIn()
	: Base()
	, Mode(GL::DrawMode::Triangles)
	, MainBuffer(GL::BufferDataUsage::StaticDraw)
	, InstBuffer(GL::BufferDataUsage::DynamicDraw)
	, MainLayout(nullptr)
	, InstLayout(nullptr)
{ }



void VertexArray::MainInstIn::Create()
{
	Base::Create();
	MainBuffer.Create();
	InstBuffer.Create();
}
void VertexArray::MainInstIn::Delete()
{
	Base::Delete();
	MainBuffer.Delete();
	InstBuffer.Delete();
}

void VertexArray::MainInstIn::Init()
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

void VertexArray::MainInstIn::Draw()
{
	Bind();
	GL::DrawArraysInstanced(Mode, 0, MainBuffer.Count, InstBuffer.Count);
}
