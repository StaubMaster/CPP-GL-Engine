#include "Graphics/Buffer/VertexArray.hpp"
#include "Graphics/Buffer/Base.hpp"
#include "OpenGL.hpp"

#include "Debug.hpp"
#include <sstream>



VertexArray::~VertexArray()
{ }
VertexArray::VertexArray()
	: ID(0)
	, Buffers()
{ }

VertexArray::VertexArray(const VertexArray & other)
	: ID(other.ID)
	, Buffers()
{ }
VertexArray & VertexArray::operator=(const VertexArray & other)
{
	ID = other.ID;
	return *this;
}



bool VertexArray::Exists() const { return (ID != 0); }
bool VertexArray::IsBound() const { return (Bound() == ID); }
void VertexArray::Bind()
{
	if (Exists() && !IsBound())
	{
		GL::BindVertexArray(ID);
	}
}

GL::VertexArrayID VertexArray::Bound()
{
	return GL::GetIntegerv(GL::ParameterName::VertexArrayBinding);
}
void VertexArray::BindNone()
{
	GL::BindVertexArray(0);
}



void VertexArray::Create()
{
	if (ID != 0) { return; }

	Debug::Log << "Buffer::ArrayBase Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateVertexArray();
	Debug::Log << "Buffer::ArrayBase Creating " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Create();
	}

	Debug::Log << "Create BufferArray: " << ID << Debug::Done;
	LogInfo();
}
void VertexArray::Delete()
{
	if (ID == 0) { return; }

	Debug::Log << "Delete BufferArray: " << ID << Debug::Done;
	LogInfo();

	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteVertexArray(ID);
	ID = 0;
	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Delete();
	}
}



void VertexArray::Draw() { }
