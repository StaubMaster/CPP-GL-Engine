#include "Graphics/Buffer/ArrayBase.hpp"
#include "Graphics/Buffer/Base.hpp"
#include "OpenGL/openGL.h"
#include "Debug.hpp"
#include <sstream>



BufferArrayID BufferArray::Base::None = 0;

void BufferArray::Base::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Buffer Array Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	Debug::Log << Debug::Tabs << "Buffers[" << Buffers.Count() << "]\n";
	Debug::Log << Debug::TabInc;
	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> LogInfo(false);
	}
	Debug::Log << Debug::TabDec;
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



BufferArray::Base::Base() :
	ID(None),
	Buffers()
{ }
BufferArray::Base::~Base()
{ }
BufferArray::Base::Base(const Base & other) :
	ID(other.ID)
	//Buffers(other.Buffers)
{ }
BufferArray::Base & BufferArray::Base::operator=(const Base & other)
{
	ID = other.ID;
	//Buffers = other.Buffers;
	return *this;
}



bool BufferArray::Base::Exists() const { return (ID != None); }
bool BufferArray::Base::IsBound() const { return (Bound() == ID); }
void BufferArray::Base::Bind()
{
	if (!IsBound())
	{
		glBindVertexArray(ID);
	}
}

BufferArrayID BufferArray::Base::Bound()
{
	int ID;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &ID);
	return ID;
}
void BufferArray::Base::BindNone()
{
	glBindVertexArray(None);
}



void BufferArray::Base::Create()
{
	if (ID != None) { return; }

	//Debug::Log << "Buffer::ArrayBase Creating " << ID << " ..." << Debug::Done;
	glGenVertexArrays(1, &ID);
	//Debug::Log << "Buffer::ArrayBase Creating " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Create();
	}

	//Debug::Log << "Create BufferArray: " << ID << Debug::Done;
	//LogInfo();
}
void BufferArray::Base::Delete()
{
	if (ID == None) { return; }

	//Debug::Log << "Delete BufferArray: " << ID << Debug::Done;
	//LogInfo();

	//Debug::Log << "Buffer::ArrayBase Deleting " << ID << " ..." << Debug::Done;
	glDeleteVertexArrays(1, &ID);
	ID = None;
	//Debug::Log << "Buffer::ArrayBase Deleting " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Delete();
	}
}



void BufferArray::Base::Draw() { }