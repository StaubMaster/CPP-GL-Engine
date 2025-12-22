#include "Graphics/Buffer/Attribute.hpp"
#include "Debug.hpp"
#include "OpenGL/openGL.h"
#include <sstream>



Buffer::Attribute::Attribute() :
	Buffer::Base(),
	Attributes(),
	Count(0)
{
	Debug::Log << "++++ Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute::~Attribute()
{
	Debug::Log << "---- Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute::Attribute(const Attribute & other) :
	Buffer::Base(other),
	Attributes(other.Attributes),
	Count(other.Count)
{
	Debug::Log << "==== Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute & Buffer::Attribute::operator=(const Attribute & other)
{
	Debug::Log << "==== Buffer::Attribute " << " operator=" << Debug::Done;
	*((Base*)this) = other;
	Attributes = other.Attributes;
	Count = other.Count;
	Debug::Log << "==== Buffer::Attribute " << " operator=done" << Debug::Done;
	return *this;
}



void Buffer::Attribute::CreateRelay() { }
void Buffer::Attribute::DeleteRelay() { }
void Buffer::Attribute::BindRelay()
{
	const unsigned char * offset;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(offset);
	}
}