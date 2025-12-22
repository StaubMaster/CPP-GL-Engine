#include "Graphics/Buffer/ArrayBase.hpp"
#include "Debug.hpp"
#include "OpenGL/openGL.h"
#include <sstream>



Buffer::ArrayBase::ArrayBase() :
	ID(0)
{
	Debug::Log << "++++ Buffer::ArrayBase " << ID << Debug::Done;
}
Buffer::ArrayBase::~ArrayBase()
{
	Debug::Log << "---- Buffer::ArrayBase " << ID << Debug::Done;
}
Buffer::ArrayBase::ArrayBase(const ArrayBase & other) :
	ID(other.ID)
{
	Debug::Log << "==== Buffer::ArrayBase " << ID << Debug::Done;
}
Buffer::ArrayBase & Buffer::ArrayBase::operator=(const ArrayBase & other)
{
	Debug::Log << "==== Buffer::ArrayBase " << ID << " operator=" << Debug::Done;
	ID = other.ID;
	return *this;
}



bool Buffer::ArrayBase::Exists() const { return (ID != 0); }
bool Buffer::ArrayBase::IsBound() const { return (Bound() == ID); }
void Buffer::ArrayBase::Bind()
{
	if (!IsBound())
	{
		glBindVertexArray(ID);
	}
}

unsigned int Buffer::ArrayBase::Bound()
{
	int ID;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &ID);
	return ID;
}
void Buffer::ArrayBase::BindNone()
{
	glBindVertexArray(0);
}



void Buffer::ArrayBase::Create()
{
	if (ID != 0) { return; }
	Debug::Log << "Buffer::ArrayBase Creating " << ID << " ..." << Debug::Done;
	glGenVertexArrays(1, &ID);
	CreateBuffers();
	Debug::Log << "Buffer::ArrayBase Creating " << ID << " done" << Debug::Done;
}
void Buffer::ArrayBase::Delete()
{
	if (ID == 0) { return; }
	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " ..." << Debug::Done;
	glDeleteVertexArrays(1, &ID);
	DeleteBuffers();
	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " done" << Debug::Done;
}

void Buffer::ArrayBase::CreateBuffers() { }
void Buffer::ArrayBase::DeleteBuffers() { }



void Buffer::ArrayBase::Draw() { }