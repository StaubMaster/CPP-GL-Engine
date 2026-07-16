#include "Graphics/VertexArray/Main.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"



VertexArray::Main::~Main()
{ }
VertexArray::Main::Main()
	: Base()
	, Mode(GL::DrawMode::Triangles)
	, MainBuffer(GL::BufferDataUsage::StaticDraw)
	, MainLayout(nullptr)
{ }



void VertexArray::Main::Create()
{
	Base::Create();
	MainBuffer.Create();
}
void VertexArray::Main::Delete()
{
	Base::Delete();
	MainBuffer.Delete();
}

void VertexArray::Main::Init()
{
	Bind();

	MainBuffer.Bind();
	if (MainLayout != nullptr)
	{
		MainLayout -> Bind();
	}
}

void VertexArray::Main::Draw()
{
	GL::DrawArrays(Mode, 0, MainBuffer.Count);
}
