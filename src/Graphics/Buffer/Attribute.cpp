#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL.hpp"

//#include "OpenGL/Errors.hpp"
#include "Debug.hpp"
#include <sstream>
//#include <iostream>



void Buffer::Attribute::LogInfo(bool self) const
{
	(void)self;
	Debug::Log << Debug::Tabs << "Buffer::Attribute\n";
	Debug::Log << Debug::TabInc;
	Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	Debug::Log << Debug::Tabs << "Divisor: " << Divisor << '\n';
	Debug::Log << Debug::Tabs << "Stride: " << Stride << '\n';
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> LogInfo();
	}
	Debug::Log << Debug::TabDec;
}



Buffer::Attribute::~Attribute()
{ }
Buffer::Attribute::Attribute(::BufferArray::Base & buffer_array, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, GL::AttributeStride stride)
	: Buffer::Base(buffer_array, GL::BufferTarget::ArrayBuffer)
	, Usage(usage)
	, Divisor(divisor)
	, Stride(stride)
	, DrawCount(0)
	, Attributes()
{ }
Buffer::Attribute::Attribute(const Attribute & other)
	: Buffer::Base(other)
	, Usage(other.Usage)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
	, DrawCount(other.DrawCount)
	, Attributes(other.Attributes)
{ }
Buffer::Attribute & Buffer::Attribute::operator=(const Attribute & other)
{
	Base::operator=(other);
	Usage = other.Usage;
	Divisor = other.Divisor;
	Stride = other.Stride;
	DrawCount = other.DrawCount;
	return *this;
}



void Buffer::Attribute::Change(const Container::Void & data)
{
	Bind();
	GL::BufferData(Target, data.VoidCount(), data.VoidData(), Usage);

	GL::AttributeOffset offset = nullptr;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(Divisor, Stride, offset);
	}

	DrawCount = data.Count();
}
