#include "PolyHedra/Main/Buffer.hpp"
#include "PolyHedra/Main/Data.hpp"



PolyHedra_Main::Buffer::~Buffer() { }

PolyHedra_Main::Buffer::Buffer(BufferArray::Base & buffer_array)
	: ::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(PolyHedra_Main::Data))
	, Position()
	, Normal()
	, Texture()
{
	Attributes.Allocate(3);
	Attributes.Insert(&Position);
	Attributes.Insert(&Normal);
	Attributes.Insert(&Texture);
}

PolyHedra_Main::Buffer::Buffer(const PolyHedra_Main::Buffer & other) :
	Buffer::Attribute(other),
	Position(other.Position),
	Normal(other.Normal),
	Texture(other.Texture)
{ }
PolyHedra_Main::Buffer & PolyHedra_Main::Buffer::operator=(const PolyHedra_Main::Buffer & other)
{
	::Buffer::Attribute::operator=(other);
	Position = other.Position;
	Normal = other.Normal;
	Texture = other.Texture;
	return *this;
}
