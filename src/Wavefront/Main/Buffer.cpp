#include "Wavefront/Main/Buffer.hpp"
#include "Wavefront/Main/Data.hpp"
#include "OpenGL.hpp"



Wavefront::Main::Buffer::Buffer(
	BufferArray::Base & buffer_array,
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor,
	unsigned int indexAmbientColor,
	unsigned int indexDiffuseColor,
	unsigned int indexSpecularPower,
	unsigned int indexSpecularColor
) :	::Buffer::Attribute(buffer_array, GL::BufferDataUsage::StaticDraw, 0, sizeof(Main::Data)),
	Position(*this, indexPosition),
	Texture(*this, indexTexture),
	Normal(*this, indexNormal),
	Color(*this, indexColor),
	AmbientColor(*this, indexAmbientColor),
	DiffuseColor(*this, indexDiffuseColor),
	SpecularPower(*this, indexSpecularPower),
	SpecularColor(*this, indexSpecularColor)
{
	Attributes.Allocate(8);
	Attributes.Insert(&Position);
	Attributes.Insert(&Texture);
	Attributes.Insert(&Normal);
	Attributes.Insert(&Color);
	Attributes.Insert(&AmbientColor);
	Attributes.Insert(&DiffuseColor);
	Attributes.Insert(&SpecularPower);
	Attributes.Insert(&SpecularColor);
}
Wavefront::Main::Buffer::~Buffer()
{ }
