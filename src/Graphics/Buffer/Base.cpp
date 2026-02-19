#include "Graphics/Buffer/Base.hpp"
#include "Graphics/Buffer/ArrayBase.hpp"

#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>
#include <iostream>



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



Buffer::Base::~Base()
{ }
Buffer::Base::Base(::BufferArray::Base & buffer_array, GL::BufferTarget target)
	: BufferArray(buffer_array)
	, Target(target)
	, ID(0)
{ }

Buffer::Base::Base(const Base & other)
	: BufferArray(other.BufferArray)
	, Target(other.Target)
	, ID(other.ID)
{ }
Buffer::Base & Buffer::Base::operator=(const Base & other)
{
	Target = other.Target;
	ID = other.ID;
	return *this;
}



void Buffer::Base::Create()
{
	if (ID != 0) { return; }

	//Debug::Log << "Buffer::Base Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateBuffer();
	//Debug::Log << "Buffer::Base Creating " << ID << " done" << Debug::Done;
}
void Buffer::Base::Delete()
{
	if (ID == 0) { return; }

	//Debug::Log << "Buffer::Base Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteBuffer(ID);
	ID = 0;
	//Debug::Log << "Buffer::Base Deleting " << ID << " done" << Debug::Done;
}

void Buffer::Base::Bind()
{
	BufferArray.Bind();
	GL::BindBuffer(Target, ID);
}
