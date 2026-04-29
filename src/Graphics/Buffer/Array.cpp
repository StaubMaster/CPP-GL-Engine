#include "Graphics/Buffer/Array.hpp"
#include "OpenGL.hpp"

//#include "OpenGL/Errors.hpp"
#include "Debug.hpp"
#include <sstream>
//#include <iostream>



void Buffer::Array::LogInfo(bool self) const
{
	(void)self;
	//Debug::Log << Debug::Tabs << "Buffer::Array\n";
	//Debug::Log << Debug::TabInc;
	//Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	//Debug::Log << Debug::Tabs << "Usade: " << Usage << '\n';
	//Debug::Log << Debug::Tabs << "Divisor: " << Divisor << '\n';
	//Debug::Log << Debug::Tabs << "Stride: " << Stride << '\n';
	//for (unsigned int i = 0; i < Attributes.Count(); i++)
	//{
	//	Attributes[i] -> LogInfo();
	//}
	//Debug::Log << Debug::TabDec;
}



Buffer::Array::~Array()
{ }
Buffer::Array::Array(VertexArray & vertex_array, GL::BufferDataUsage usage, GL::AttributeDivisor divisor, GL::AttributeStride stride)
	: Buffer::Base(vertex_array, GL::BufferTarget::ArrayBuffer, usage)
	, Divisor(divisor)
	, Stride(stride)
	, Count(0)
	, Attributes()
{ }
Buffer::Array::Array(const Array & other)
	: Buffer::Base(other)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
	, Count(other.Count)
	, Attributes(other.Attributes)
{ }
Buffer::Array & Buffer::Array::operator=(const Array & other)
{
	Base::operator=(other);
	Divisor = other.Divisor;
	Stride = other.Stride;
	Count = other.Count;
	return *this;
}



void Buffer::Array::Init()
{
	Base::Data();
	GL::AttributeOffset offset = nullptr;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(Divisor, Stride, offset);
	}
}
void Buffer::Array::Data(const Container::Void & data)
{
	Base::Data(data);
	Count = data.VoidCount() / Stride;
}
