#include "Waveform/OBJ_Main.hpp"

#include "OpenGL.hpp"



OBJ_MainBuffer::OBJ_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor,
	unsigned int indexAmbientColor,
	unsigned int indexDiffuseColor,
	unsigned int indexSpecularPower,
	unsigned int indexSpecularColor
) :
	//BaseBuffer(1, (Attribute::Base * []) {
	//	new OBJ_MainAttrib(0, sizeof(OBJ_MainData), indexPosition, indexTexture, indexNormal, indexColor,
	//	indexAmbientColor, indexDiffuseColor, indexSpecularPower, indexSpecularColor)
	//}) { }
	Buffer::Attribute(GL::BufferTarget::ArrayBuffer, GL::BufferDataUsage::StaticDraw, sizeof(OBJ_MainData)),
	//Attribute(0, sizeof(OBJ_MainData), indexPosition, indexTexture, indexNormal, indexColor, indexAmbientColor, indexDiffuseColor, indexSpecularPower, indexSpecularColor)
	Position(0, sizeof(OBJ_MainData), indexPosition),
	Texture(0, sizeof(OBJ_MainData), indexTexture),
	Normal(0, sizeof(OBJ_MainData), indexNormal),
	Color(0, sizeof(OBJ_MainData), indexColor),
	AmbientColor(0, sizeof(OBJ_MainData), indexAmbientColor),
	DiffuseColor(0, sizeof(OBJ_MainData), indexDiffuseColor),
	SpecularPower(0, sizeof(OBJ_MainData), indexSpecularPower),
	SpecularColor(0, sizeof(OBJ_MainData), indexSpecularColor)
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
OBJ_MainBuffer::~OBJ_MainBuffer()
{ }
