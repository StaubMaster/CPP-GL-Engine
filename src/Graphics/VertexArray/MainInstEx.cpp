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



void VertexArray::MainInstEx::MainChange(::Buffer::Array & buffer, Attribute::Layout & layout, unsigned int size_of)
{
	MainBuffer = &buffer;
	MainLayout = &layout;
	MainBuffer -> SizeOf = size_of;
}
void VertexArray::MainInstEx::InstChange(::Buffer::Array & buffer, Attribute::Layout & layout, unsigned int size_of)
{
	InstBuffer = &buffer;
	InstLayout = &layout;
	InstBuffer -> SizeOf = size_of;
}

void VertexArray::MainInstEx::MainChange(::Buffer::Array * buffer, Attribute::Layout * layout, unsigned int size_of)
{
	if (buffer != nullptr && layout != nullptr)
	{
		MainChange(*buffer, *layout, size_of);
	}
}
void VertexArray::MainInstEx::InstChange(::Buffer::Array * buffer, Attribute::Layout * layout, unsigned int size_of)
{
	if (buffer != nullptr && layout != nullptr)
	{
		InstChange(*buffer, *layout, size_of);
	}
}



void VertexArray::MainInstEx::MainData(const Container::Void & data)
{
	if (MainBuffer != nullptr)
	{
		MainBuffer -> DataFull(data);
	}
}
void VertexArray::MainInstEx::InstData(const Container::Void & data)
{
	if (InstBuffer != nullptr)
	{
		InstBuffer -> DataFull(data);
	}
}



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
	if (MainBuffer != nullptr && InstBuffer != nullptr)
	{
		GL::DrawArraysInstanced(Mode, 0, MainBuffer -> Count, InstBuffer -> Count);
	}
}
