#include "Graphics/Buffer/Base.hpp"
#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>
#include <iostream>



BufferID Buffer::Base::None = 0;

void Buffer::Base::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Buffer Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Buffer::Base::Base() :
	ID(None)
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
	if (ID != None) { return; }

	//Debug::Log << "Buffer::Base Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateBuffer();
	//Debug::Log << "Buffer::Base Creating " << ID << " done" << Debug::Done;
}
void Buffer::Base::Delete()
{
	if (ID == None) { return; }

	//Debug::Log << "Buffer::Base Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteBuffer(ID);
	ID = None;
	//Debug::Log << "Buffer::Base Deleting " << ID << " done" << Debug::Done;
}
