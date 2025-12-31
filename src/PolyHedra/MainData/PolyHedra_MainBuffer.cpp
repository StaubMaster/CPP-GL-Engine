#include "PolyHedra/MainData//PolyHedra_MainBuffer.hpp"
#include "PolyHedra/MainData//PolyHedra_MainData.hpp"



PolyHedra_MainBuffer::PolyHedra_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexNormal,
	unsigned int indexTexture
) :
	Buffer::Attribute(GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(PolyHedra_MainData)),
	Position(0, sizeof(PolyHedra_MainData), indexPosition),
	Normal(0, sizeof(PolyHedra_MainData), indexNormal),
	Texture(0, sizeof(PolyHedra_MainData), indexTexture)
{
	Attributes.Allocate(3);
	Attributes.Insert(&Position);
	Attributes.Insert(&Normal);
	Attributes.Insert(&Texture);
}
PolyHedra_MainBuffer::~PolyHedra_MainBuffer()
{ }
