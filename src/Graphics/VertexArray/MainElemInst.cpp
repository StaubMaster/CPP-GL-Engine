#include "Graphics/VertexArray/MainElemInst.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"



VertexArray::MainElemInst::~MainElemInst()
{ }
VertexArray::MainElemInst::MainElemInst()
	: Base()
	, Mode(GL::DrawMode::Lines)
	, MainBuffer(GL::BufferDataUsage::StaticDraw)
	, ElemBuffer(GL::BufferDataUsage::StaticDraw, GL::DrawIndexType::UnsignedInt)
	, InstBuffer(GL::BufferDataUsage::DynamicDraw)
	, MainLayout(nullptr)
	, InstLayout(nullptr)
{ }



void VertexArray::MainElemInst::Create()
{
	Base::Create();
	MainBuffer.Create();
	ElemBuffer.Create();
	InstBuffer.Create();
}
void VertexArray::MainElemInst::Delete()
{
	Base::Delete();
	MainBuffer.Delete();
	ElemBuffer.Delete();
	InstBuffer.Delete();
}

void VertexArray::MainElemInst::Init()
{
	Bind();

	MainBuffer.Bind();
	if (MainLayout != nullptr)
	{
		MainLayout -> Bind();
	}

	ElemBuffer.Bind();

	InstBuffer.Bind();
	if (InstLayout != nullptr)
	{
		InstLayout -> Bind();
	}
}

void VertexArray::MainElemInst::Draw()
{
	GL::DrawElementsInstanced(Mode, ElemBuffer.Count, ElemBuffer.IndexType, InstBuffer.Count);
}
