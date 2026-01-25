#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL.hpp"

//#include "OpenGL/Errors.hpp"
//#include "Debug.hpp"
//#include <sstream>



Buffer::Attribute::Attribute() :
	Buffer::Base(),
	Target((GL::BufferTarget)0),
	Usage((GL::BufferDataUsage)0),
	DataSize(0),
	Attributes(),
	DrawCount(0)
{ }
Buffer::Attribute::Attribute(GL::BufferTarget target, GL::BufferDataUsage usage, unsigned int data_size) :
	Buffer::Base(),
	Target(target),
	Usage(usage),
	DataSize(data_size),
	Attributes(),
	DrawCount(0)
{ }
Buffer::Attribute::~Attribute()
{ }
Buffer::Attribute::Attribute(const Attribute & other) :
	Buffer::Base(other),
	Target(other.Target),
	Usage(other.Usage),
	DataSize(other.DataSize),
	Attributes(other.Attributes),
	DrawCount(other.DrawCount)
{ }
Buffer::Attribute & Buffer::Attribute::operator=(const Attribute & other)
{
	Base::operator=(other);
	Target = other.Target;
	Usage = other.Usage;
	DataSize = other.DataSize;
	Attributes = other.Attributes;
	DrawCount = other.DrawCount;
	return *this;
}



void Buffer::Attribute::Change(const Container::Void & data)
{
	GL::BindBuffer(Target, ID);
	GL::BufferData(Target, data.VoidCount(), data.VoidData(), Usage);
	DrawCount = data.Count();

	const unsigned char * offset = NULL;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(offset);
	}
}
