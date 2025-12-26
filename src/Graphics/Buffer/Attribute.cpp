#include "Graphics/Buffer/Attribute.hpp"
#include "Debug.hpp"
#include "OpenGL/openGL.h"
#include <sstream>



Buffer::Attribute::Attribute() :
	Buffer::Base(),
	Target(0),
	Usage(0),
	DataSize(0),
	Attributes(),
	DrawCount(0)
{
	Debug::Log << "++++ Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute::Attribute(unsigned int target, unsigned int usage, unsigned int data_size) :
	Buffer::Base(),
	Target(target),
	Usage(usage),
	DataSize(data_size),
	Attributes(),
	DrawCount(0)
{
	Debug::Log << "++++ Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute::~Attribute()
{
	Debug::Log << "---- Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute::Attribute(const Attribute & other) :
	Buffer::Base(other),
	Target(other.Target),
	Usage(other.Usage),
	DataSize(other.DataSize),
	Attributes(other.Attributes),
	DrawCount(other.DrawCount)
{
	Debug::Log << "==== Buffer::Attribute " << Debug::Done;
}
Buffer::Attribute & Buffer::Attribute::operator=(const Attribute & other)
{
	Debug::Log << "==== Buffer::Attribute " << " operator=" << Debug::Done;
	*((Base*)this) = other;
	Target = other.Target;
	Usage = other.Usage;
	DataSize = other.DataSize;
	Attributes = other.Attributes;
	DrawCount = other.DrawCount;
	Debug::Log << "==== Buffer::Attribute " << " operator=done" << Debug::Done;
	return *this;
}



void Buffer::Attribute::Bind(const void * data, unsigned int count)
{
	glBindBuffer(Target, ID);
	glBufferData(Target, DataSize * count, data, Usage);
	DrawCount = count;

	const unsigned char * offset = NULL;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(offset);
	}
}
