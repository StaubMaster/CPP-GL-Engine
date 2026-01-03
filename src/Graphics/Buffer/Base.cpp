#include "Graphics/Buffer/Base.hpp"
#include "Debug.hpp"
#include "OpenGL/openGL.h"
#include <sstream>



Buffer::Base::Base() :
	ID(0)
{ }
Buffer::Base::~Base()
{ }

Buffer::Base::Base(const Base & other) :
	ID(other.ID)
{ }
Buffer::Base & Buffer::Base::operator=(const Base & other)
{
	ID = other.ID;
	return *this;
}



void Buffer::Base::Create()
{
	if (ID != 0) { return; }
	Debug::Log << "Buffer::Base Creating " << ID << " ..." << Debug::Done;
	glGenBuffers(1, &ID);
	CreateRelay();
	Debug::Log << "Buffer::Base Creating " << ID << " done" << Debug::Done;
}
void Buffer::Base::Delete()
{
	if (ID == 0) { return; }
	Debug::Log << "Buffer::Base Deleting " << ID << " ..." << Debug::Done;
	DeleteRelay();
	glDeleteBuffers(1, &ID);
	ID = 0;
	Debug::Log << "Buffer::Base Deleting " << ID << " done" << Debug::Done;
}



void Buffer::Base::CreateRelay() { }
void Buffer::Base::DeleteRelay() { }
