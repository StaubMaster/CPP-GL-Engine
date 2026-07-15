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



void VertexArray::MainInstIn::MainChange(Attribute::Layout & layout, unsigned int size_of)
{
	MainLayout = &layout;
	MainBuffer.SizeOf = size_of;
}
void VertexArray::MainInstIn::InstChange(Attribute::Layout & layout, unsigned int size_of)
{
	InstLayout = &layout;
	InstBuffer.SizeOf = size_of;
}

void VertexArray::MainInstIn::MainChange(Attribute::Layout * layout, unsigned int size_of)
{
	if (layout != nullptr)
	{
		MainChange(*layout, size_of);
	}
}
void VertexArray::MainInstIn::InstChange(Attribute::Layout * layout, unsigned int size_of)
{
	if (layout != nullptr)
	{
		InstChange(*layout, size_of);
	}
}



void VertexArray::MainInstIn::MainData(const Container::Void & data)
{
	MainBuffer.DataFull(data);
}
void VertexArray::MainInstIn::InstData(const Container::Void & data)
{
	InstBuffer.DataFull(data);
}



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
	GL::DrawArraysInstanced(Mode, 0, MainBuffer.Count, InstBuffer.Count);
}
