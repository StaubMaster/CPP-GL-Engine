#include "Graphics/VertexArray/MainInstEx.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"



VertexArray::MainInstEx::~MainInstEx()
{ }
VertexArray::MainInstEx::MainInstEx()
	: Base()
	, Mode(GL::DrawMode::Triangles)
	, MainBuffer(nullptr)
	, InstBuffer(nullptr)
	, MainLayout(nullptr)
	, InstLayout(nullptr)
{ }



/*void VertexArray::MainInstEx::Create()
{
	Base::Create();
	MainBuffer.Create();
	InstBuffer.Create();
}*/
/*void VertexArray::MainInstEx::Delete()
{
	Base::Delete();
	MainBuffer.Delete();
	InstBuffer.Delete();
}*/

void VertexArray::MainInstEx::Init()
{
	Bind();

	if (MainBuffer != nullptr)
	{
		MainBuffer -> Bind();
		if (MainLayout != nullptr)
		{
			MainLayout -> Bind();
		}
	}

	if (InstBuffer != nullptr)
	{
		InstBuffer -> Bind();
		if (InstLayout != nullptr)
		{
			InstLayout -> Bind();
		}
	}
}

void VertexArray::MainInstEx::Draw()
{
	Bind();
	if (MainBuffer != nullptr && InstBuffer != nullptr)
	{
		GL::DrawArraysInstanced(Mode, 0, MainBuffer -> Count, InstBuffer -> Count);
	}
}
