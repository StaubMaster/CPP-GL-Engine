#include "Wavefront/Main/Buffer.hpp"
#include "Wavefront/Main/Data.hpp"
#include "OpenGL.hpp"



Wavefront::Main::Buffer::Buffer(
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor,
	unsigned int indexAmbientColor,
	unsigned int indexDiffuseColor,
	unsigned int indexSpecularPower,
	unsigned int indexSpecularColor
) :
	::Buffer::Attribute(GL::BufferTarget::ArrayBuffer, GL::BufferDataUsage::StaticDraw, sizeof(Main::Data)),
	Position(0, sizeof(Main::Data), indexPosition),
	Texture(0, sizeof(Main::Data), indexTexture),
	Normal(0, sizeof(Main::Data), indexNormal),
	Color(0, sizeof(Main::Data), indexColor),
	AmbientColor(0, sizeof(Main::Data), indexAmbientColor),
	DiffuseColor(0, sizeof(Main::Data), indexDiffuseColor),
	SpecularPower(0, sizeof(Main::Data), indexSpecularPower),
	SpecularColor(0, sizeof(Main::Data), indexSpecularColor)
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
