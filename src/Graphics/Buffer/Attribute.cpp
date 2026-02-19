#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL.hpp"

//#include "OpenGL/Errors.hpp"
//#include "Debug.hpp"
//#include <sstream>
//#include <iostream>



Buffer::Attribute::Attribute()
	: Buffer::Base()
	, Target((GL::BufferTarget)0)
	, Usage((GL::BufferDataUsage)0)
	, Divisor((GL::AttributeDivisor)0)
	, Stride(0)
	, DrawCount(0)
	, Attributes()
{ }
Buffer::Attribute::Attribute(GL::BufferTarget target, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, unsigned int stride)
	: Buffer::Base()
	, Target(target)
	, Usage(usage)
	, Divisor(divisor)
	, Stride(stride)
	, DrawCount(0)
	, Attributes()
{ }
Buffer::Attribute::~Attribute()
{ }
Buffer::Attribute::Attribute(const Attribute & other)
	: Buffer::Base(other)
	, Target(other.Target)
	, Usage(other.Usage)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
	, DrawCount(other.DrawCount)
	, Attributes(other.Attributes)
{ }
Buffer::Attribute & Buffer::Attribute::operator=(const Attribute & other)
{
	Base::operator=(other);
	Target = other.Target;
	Usage = other.Usage;
	Divisor = other.Divisor;
	Stride = other.Stride;
	DrawCount = other.DrawCount;
	Attributes = other.Attributes;
	return *this;
}



void Buffer::Attribute::Change(const Container::Void & data)
{
	GL::BindBuffer(Target, ID);
	GL::BufferData(Target, data.VoidCount(), data.VoidData(), Usage);

	GL::AttributeOffset offset = nullptr;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(Divisor, Stride, offset);
	}

	DrawCount = data.Count();
}
